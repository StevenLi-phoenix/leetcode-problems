// @leetcode id=3592 questionId=3903 slug=inverse-coin-change lang=cpp site=leetcode.com title="Inverse Coin Change"
class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        // Convert to 1-indexed by prepending base case 1
        // Use a dp array where dp[0] = 1 (base), dp[1..n] = numWays[0..n-1]
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) dp[i] = numWays[i - 1];
        
        vector<int> ans;
        for (int c = 1; c <= n; c++) {
            if (dp[c] == 1) {
                ans.push_back(c);
                // Right to left removal (reverse of unbounded knapsack build)
                // This is actually left-to-right to undo unbounded (goes right to left 
                // to undo the LEFT-to-right build, i.e., we need right-to-left here)
                for (int s = n; s >= c; s--) {
                    dp[s] -= dp[s - c];
                }
            } else if (dp[c] < 0) {
                return {};
            }
        }
        
        // Check all zeros except base
        for (int i = 1; i <= n; i++) {
            if (dp[i] != 0) return {};
        }
        return ans;
    }
};
