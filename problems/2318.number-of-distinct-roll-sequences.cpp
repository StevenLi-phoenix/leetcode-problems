// @leetcode id=2318 questionId=2404 slug=number-of-distinct-roll-sequences lang=cpp site=leetcode.com title="Number of Distinct Roll Sequences"
class Solution {
public:
    int distinctSequences(int n) {
        const int MOD = 1e9 + 7;
        // dp[last][second_last] = number of sequences ending with last, prev was second_last
        // dice values 1-6, use 0-indexed as 1-6, 0 = no previous
        // dp[i][j]: last=i (1-6), second_last=j (0-6, 0 means none)
        vector<vector<long long>> dp(7, vector<long long>(7, 0));
        
        // Initialize for length 1: any die value
        for (int i = 1; i <= 6; i++) dp[i][0] = 1;
        
        for (int roll = 2; roll <= n; roll++) {
            vector<vector<long long>> ndp(7, vector<long long>(7, 0));
            for (int last = 1; last <= 6; last++) {
                for (int prev = 0; prev <= 6; prev++) {
                    if (dp[last][prev] == 0) continue;
                    // try next die value
                    for (int next = 1; next <= 6; next++) {
                        if (next == last) continue;       // no same adjacent
                        if (next == prev) continue;       // gap of at least 2
                        if (__gcd(next, last) != 1) continue; // gcd must be 1
                        ndp[next][last] = (ndp[next][last] + dp[last][prev]) % MOD;
                    }
                }
            }
            dp = ndp;
        }
        
        long long ans = 0;
        for (int i = 1; i <= 6; i++)
            for (int j = 0; j <= 6; j++)
                ans = (ans + dp[i][j]) % MOD;
        return ans;
    }
};
