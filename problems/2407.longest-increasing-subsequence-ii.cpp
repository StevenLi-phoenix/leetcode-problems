// @leetcode id=2407 questionId=2526 slug=longest-increasing-subsequence-ii lang=cpp site=leetcode.com title="Longest Increasing Subsequence II"
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        // Segment tree over value [1, maxVal] storing, at each value v,
        // the best chain length ending with that exact value. For each
        // num, query the max over [num-k, num-1] and extend by one.
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> tree(4 * (maxVal + 1), 0);

        function<void(int, int, int, int, int)> update = [&](int node, int lo, int hi, int pos, int val) {
            if (lo == hi) {
                tree[node] = max(tree[node], val);
                return;
            }
            int mid = (lo + hi) / 2;
            if (pos <= mid) update(node * 2, lo, mid, pos, val);
            else update(node * 2 + 1, mid + 1, hi, pos, val);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        };

        function<int(int, int, int, int, int)> query = [&](int node, int lo, int hi, int l, int r) -> int {
            if (r < lo || hi < l || l > r) return 0;
            if (l <= lo && hi <= r) return tree[node];
            int mid = (lo + hi) / 2;
            return max(query(node * 2, lo, mid, l, r), query(node * 2 + 1, mid + 1, hi, l, r));
        };

        int best = 0;
        for (int v : nums) {
            int lo = max(1, v - k);
            int prevBest = (v > lo) ? query(1, 1, maxVal, lo, v - 1) : 0;
            int cur = prevBest + 1;
            update(1, 1, maxVal, v, cur);
            best = max(best, cur);
        }
        return best;
    }
};
