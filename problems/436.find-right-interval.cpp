// @leetcode id=436 questionId=436 slug=find-right-interval lang=cpp site=leetcode.com title="Find Right Interval"
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts(n); // (start value, original index)
        for (int i = 0; i < n; i++) starts[i] = {intervals[i][0], i};
        sort(starts.begin(), starts.end());

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            int lo = 0, hi = n; // first index with starts[idx].first >= end
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (starts[mid].first >= end) hi = mid;
                else lo = mid + 1;
            }
            ans[i] = (lo == n) ? -1 : starts[lo].second;
        }
        return ans;
    }
};
