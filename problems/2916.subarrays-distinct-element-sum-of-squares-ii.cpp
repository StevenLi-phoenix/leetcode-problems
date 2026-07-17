// @leetcode id=2916 questionId=3139 slug=subarrays-distinct-element-sum-of-squares-ii lang=cpp site=leetcode.com title="Subarrays Distinct Element Sum of Squares II"
class Solution {
public:
    static const long long MOD = 1e9 + 7;

    struct Node {
        long long cnt = 0, sumD = 0, sumD2 = 0, lazy = 0;
    };

    vector<Node> tree;

    void build(int node, int l, int r) {
        tree[node].cnt = r - l + 1;
        if (l == r) return;
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
    }

    void applyDelta(int node, long long delta) {
        Node& t = tree[node];
        t.sumD2 = (t.sumD2 + 2 * delta % MOD * t.sumD + delta * delta % MOD * t.cnt) % MOD;
        t.sumD = (t.sumD + delta * t.cnt) % MOD;
        t.lazy += delta;
    }

    void push(int node) {
        if (tree[node].lazy != 0) {
            applyDelta(2 * node, tree[node].lazy);
            applyDelta(2 * node + 1, tree[node].lazy);
            tree[node].lazy = 0;
        }
    }

    void rangeAdd(int node, int l, int r, int ql, int qr, long long delta) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { applyDelta(node, delta); return; }
        push(node);
        int mid = (l + r) / 2;
        rangeAdd(2 * node, l, mid, ql, qr, delta);
        rangeAdd(2 * node + 1, mid + 1, r, ql, qr, delta);
        tree[node].sumD = (tree[2 * node].sumD + tree[2 * node + 1].sumD) % MOD;
        tree[node].sumD2 = (tree[2 * node].sumD2 + tree[2 * node + 1].sumD2) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n, Node());
        build(1, 0, n - 1);

        unordered_map<int,int> lastOcc;
        long long answer = 0;

        for (int r = 0; r < n; r++) {
            int lo = lastOcc.count(nums[r]) ? lastOcc[nums[r]] + 1 : 0;
            rangeAdd(1, 0, n - 1, lo, r, 1);
            lastOcc[nums[r]] = r;

            answer = (answer + tree[1].sumD2) % MOD;
        }

        return (int)answer;
    }
};
