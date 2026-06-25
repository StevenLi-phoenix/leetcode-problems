// @leetcode id=2054 questionId=2164 slug=two-best-non-overlapping-events lang=cpp site=leetcode.com title="Two Best Non-Overlapping Events"
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0]; // sort by start time
        });

        int n = (int)events.size();
        vector<int> starts(n);
        for (int i = 0; i < n; i++) starts[i] = events[i][0];

        // sufMax[i] = maximum value among events[i..n-1]
        vector<int> sufMax(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            sufMax[i] = max(sufMax[i + 1], events[i][2]);
        }

        long long ans = sufMax[0]; // take only one event

        for (int i = 0; i < n; i++) {
            long long v = events[i][2];
            long long nextStart = (long long)events[i][1] + 1; // inclusive end => must start at end+1
            int j = (int)(lower_bound(starts.begin(), starts.end(), (int)nextStart) - starts.begin());
            ans = max(ans, v + sufMax[j]);
        }

        return (int)ans;
    }
};
