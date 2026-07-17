// @leetcode id=1235 questionId=1352 slug=maximum-profit-in-job-scheduling lang=cpp site=leetcode.com title="Maximum Profit in Job Scheduling"
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return endTime[a] < endTime[b];
        });

        vector<int> sortedEnd(n);
        vector<long long> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int idx = order[i];
            sortedEnd[i] = endTime[idx];

            int lo = 0, hi = i; // find count of jobs with endTime <= startTime[idx]
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (sortedEnd[mid] <= startTime[idx]) lo = mid + 1;
                else hi = mid;
            }

            dp[i + 1] = max(dp[i], dp[lo] + profit[idx]);
        }

        return (int)dp[n];
    }
};
