// @leetcode id=1751 questionId=1851 slug=maximum-number-of-events-that-can-be-attended-ii lang=cpp site=leetcode.com title="Maximum Number of Events That Can Be Attended II"
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        // dp[i][j] = max value attending j events from events[i..n-1]
        // Use memoization + binary search
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            // Binary search for next event that starts after events[i] ends
            int lo = i + 1, hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (events[mid][0] > events[i][1]) hi = mid;
                else lo = mid + 1;
            }
            int next = lo;
            for (int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i + 1][j], events[i][2] + dp[next][j - 1]);
            }
        }
        return dp[0][k];
    }
};
