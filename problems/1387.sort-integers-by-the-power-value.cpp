// @leetcode id=1387 questionId=1488 slug=sort-integers-by-the-power-value lang=cpp site=leetcode.com title="Sort Integers by The Power Value"
class Solution {
public:
    unordered_map<long long, int> memo;

    int power(long long x) {
        if (x == 1) return 0;
        auto it = memo.find(x);
        if (it != memo.end()) return it->second;
        int result = 1 + power(x % 2 == 0 ? x / 2 : 3 * x + 1);
        memo[x] = result;
        return result;
    }

    int getKth(int lo, int hi, int k) {
        vector<int> nums;
        for (int i = lo; i <= hi; i++) nums.push_back(i);
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int pa = power(a), pb = power(b);
            if (pa != pb) return pa < pb;
            return a < b;
        });
        return nums[k - 1];
    }
};
