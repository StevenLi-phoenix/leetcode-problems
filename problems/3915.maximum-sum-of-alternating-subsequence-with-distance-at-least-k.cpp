// @leetcode id=3915 questionId=4260 slug=maximum-sum-of-alternating-subsequence-with-distance-at-least-k lang=cpp site=leetcode.com title="Maximum Sum of Alternating Subsequence With Distance at Least K"
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();
        const int MAXV = 100001;

        struct MaxSegTree {
            vector<long long> tree;
            int size;
            MaxSegTree(int sz) : size(sz), tree(4 * sz, -1) {}
            void update(int node, int lo, int hi, int pos, long long val) {
                if (lo == hi) { tree[node] = max(tree[node], val); return; }
                int mid = (lo + hi) / 2;
                if (pos <= mid) update(2 * node, lo, mid, pos, val);
                else update(2 * node + 1, mid + 1, hi, pos, val);
                tree[node] = max(tree[2 * node], tree[2 * node + 1]);
            }
            long long query(int node, int lo, int hi, int l, int r) {
                if (r < lo || hi < l || l > r) return -1;
                if (l <= lo && hi <= r) return tree[node];
                int mid = (lo + hi) / 2;
                return max(query(2 * node, lo, mid, l, r), query(2 * node + 1, mid + 1, hi, l, r));
            }
            void insert(int pos, long long val) { update(1, 0, size - 1, pos, val); }
            long long queryRange(int l, int r) { return query(1, 0, size - 1, l, r); }
        };

        MaxSegTree treeLow(MAXV);
        MaxSegTree treeHigh(MAXV);

        vector<long long> dpHigh(n), dpLow(n);
        long long ans = 0;
        int insertPtr = 0;

        for (int i = 0; i < n; ++i) {
            while (insertPtr <= i - k) {
                treeLow.insert(nums[insertPtr], dpLow[insertPtr]);
                treeHigh.insert(nums[insertPtr], dpHigh[insertPtr]);
                ++insertPtr;
            }

            long long bestLowBelow = nums[i] > 0 ? treeLow.queryRange(0, nums[i] - 1) : -1;
            dpHigh[i] = nums[i] + max(0LL, bestLowBelow);

            long long bestHighAbove = treeHigh.queryRange(nums[i] + 1, MAXV - 1);
            dpLow[i] = nums[i] + max(0LL, bestHighAbove);

            ans = max({ans, dpHigh[i], dpLow[i]});
        }
        return ans;
    }
};
