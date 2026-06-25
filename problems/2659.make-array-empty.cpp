// @leetcode id=2659 questionId=2765 slug=make-array-empty lang=cpp site=leetcode.com title="Make Array Empty"
#include <bits/stdc++.h>
using namespace std;

class BIT {
    vector<long long> tree;
    int n;
public:
    BIT(int n) : n(n), tree(n + 1, 0) {}
    void update(int i, int v) {
        for (; i <= n; i += i & -i) tree[i] += v;
    }
    long long query(int i) {
        long long s = 0;
        for (; i > 0; i -= i & -i) s += tree[i];
        return s;
    }
    long long query(int l, int r) { return query(r) - query(l - 1); }
};

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        // 获取按值排序的原始下标顺序
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        BIT bit(n);
        for (int i = 1; i <= n; i++) bit.update(i, 1);

        long long ops = 0;
        int curr = 0; // 当前队头在原始数组中的下标

        for (int target : order) {
            if (target >= curr) {
                // 顺向：从 curr 到 target，计算这段还剩多少元素
                ops += bit.query(curr + 1, target + 1);
            } else {
                // 绕圈：curr→末尾 + 头→target
                ops += bit.query(curr + 1, n) + bit.query(1, target + 1);
            }
            bit.update(target + 1, -1); // 移除 target
            curr = target;              // 下一轮从 target 位置之后开始
        }

        return ops;
    }
};
