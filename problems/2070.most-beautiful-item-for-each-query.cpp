// @leetcode id=2070 questionId=2179 slug=most-beautiful-item-for-each-query lang=cpp site=leetcode.com title="Most Beautiful Item for Each Query"
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        vector<int> maxBeauty(n);
        int best = 0;
        for (int i = 0; i < n; i++) {
            best = max(best, items[i][1]);
            maxBeauty[i] = best;
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            int q = queries[i];
            int lo = 0, hi = n;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (items[mid][0] <= q) lo = mid + 1;
                else hi = mid;
            }
            ans[i] = lo == 0 ? 0 : maxBeauty[lo - 1];
        }
        return ans;
    }
};
