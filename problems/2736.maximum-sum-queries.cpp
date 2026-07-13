// @leetcode id=2736 questionId=2839 slug=maximum-sum-queries lang=cpp site=leetcode.com title="Maximum Sum Queries"
class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        // Process points in decreasing nums1 order (two-pointer keyed to
        // queries sorted by decreasing x), inserting each point's sum into
        // a Fenwick tree keyed by its nums2 rank; answer a query by taking
        // a suffix-max over ranks >= rank(y), which avoids having to keep
        // a hand-maintained Pareto frontier sorted/invariant by hand.
        int n = nums1.size(), q = queries.size();

        vector<int> valsSorted = nums2;
        sort(valsSorted.begin(), valsSorted.end());
        valsSorted.erase(unique(valsSorted.begin(), valsSorted.end()), valsSorted.end());
        int m = valsSorted.size();

        vector<long long> tree(m + 1, -1);
        auto update = [&](int i, long long val) {
            for (; i >= 1; i -= i & (-i)) tree[i] = max(tree[i], val);
        };
        auto query = [&](int i) -> long long {
            long long res = -1;
            for (; i <= m; i += i & (-i)) res = max(res, tree[i]);
            return res;
        };

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums1[a] > nums1[b]; });

        vector<int> qOrder(q);
        iota(qOrder.begin(), qOrder.end(), 0);
        sort(qOrder.begin(), qOrder.end(), [&](int a, int b) { return queries[a][0] > queries[b][0]; });

        vector<int> ans(q, -1);
        int pointer = 0;
        for (int qi : qOrder) {
            long long x = queries[qi][0], y = queries[qi][1];
            while (pointer < n && nums1[idx[pointer]] >= x) {
                int i = idx[pointer];
                int rank = lower_bound(valsSorted.begin(), valsSorted.end(), nums2[i]) - valsSorted.begin() + 1;
                update(rank, (long long)nums1[i] + nums2[i]);
                pointer++;
            }
            auto it = lower_bound(valsSorted.begin(), valsSorted.end(), y);
            if (it != valsSorted.end()) {
                int rank = it - valsSorted.begin() + 1;
                long long best = query(rank);
                ans[qi] = (best == -1) ? -1 : (int)best;
            }
        }
        return ans;
    }
};
