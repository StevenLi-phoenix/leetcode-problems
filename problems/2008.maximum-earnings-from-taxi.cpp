// @leetcode id=2008 questionId=2118 slug=maximum-earnings-from-taxi lang=cpp site=leetcode.com title="Maximum Earnings From Taxi"
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        // Bucket rides by end point; dp[p] = best earnings driving from 1 to p.
        vector<vector<pair<int, int>>> endingAt(n + 1); // point -> (start, profit)
        for (auto& r : rides)
            endingAt[r[1]].push_back({r[0], r[1] - r[0] + r[2]});

        vector<long long> dp(n + 1, 0);
        for (int p = 1; p <= n; p++) {
            dp[p] = dp[p - 1];
            for (auto [start, profit] : endingAt[p])
                dp[p] = max(dp[p], dp[start] + profit);
        }
        return dp[n];
    }
};
