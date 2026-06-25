// @leetcode id=1269 questionId=1398 slug=number-of-ways-to-stay-in-the-same-place-after-some-steps lang=cpp site=leetcode.com title="Number of Ways to Stay in the Same Place After Some Steps"
class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1e9 + 7;
        // Max useful position: we can only be at most steps/2 positions away from 0
        int maxPos = min(steps / 2, arrLen - 1);
        
        // dp[pos] = number of ways to reach position pos after current step
        vector<long long> dp(maxPos + 1, 0);
        dp[0] = 1;
        
        for (int s = 0; s < steps; s++) {
            vector<long long> ndp(maxPos + 1, 0);
            for (int pos = 0; pos <= maxPos; pos++) {
                if (dp[pos] == 0) continue;
                // Stay
                ndp[pos] = (ndp[pos] + dp[pos]) % MOD;
                // Move right
                if (pos + 1 <= maxPos) {
                    ndp[pos + 1] = (ndp[pos + 1] + dp[pos]) % MOD;
                }
                // Move left
                if (pos - 1 >= 0) {
                    ndp[pos - 1] = (ndp[pos - 1] + dp[pos]) % MOD;
                }
            }
            dp = ndp;
        }
        
        return dp[0];
    }
};
