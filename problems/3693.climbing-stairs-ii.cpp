// @leetcode id=3693 questionId=4041 slug=climbing-stairs-ii lang=cpp site=leetcode.com title="Climbing Stairs II"
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 3; k++) {
                int i = j - k;
                if (i < 0 || dp[i] == LLONG_MAX) continue;
                long long candidate = dp[i] + costs[j - 1] + (long long)k * k;
                dp[j] = min(dp[j], candidate);
            }
        }
        return (int)dp[n];
    }
};
