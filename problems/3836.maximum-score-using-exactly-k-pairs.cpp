// @leetcode id=3836 questionId=4202 slug=maximum-score-using-exactly-k-pairs lang=cpp site=leetcode.com title="Maximum Score Using Exactly K Pairs"
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        const long long NEG_INF = LLONG_MIN / 2;
        // dp[i][j][t] = max score using exactly t pairs from nums1[0..i-1] and nums2[0..j-1]
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(m+1, vector<long long>(k+1, NEG_INF)));
        dp[0][0][0] = 0;
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int t = 0; t <= k; t++) {
                    if (dp[i][j][t] == NEG_INF) continue;
                    long long val = dp[i][j][t];
                    // Take pair (nums1[i], nums2[j])
                    if (i < n && j < m && t < k) {
                        dp[i+1][j+1][t+1] = max(dp[i+1][j+1][t+1], val + (long long)nums1[i] * nums2[j]);
                    }
                    // Skip nums1[i] (advance i without pairing)
                    if (i < n) {
                        dp[i+1][j][t] = max(dp[i+1][j][t], val);
                    }
                    // Skip nums2[j] (advance j without pairing)
                    if (j < m) {
                        dp[i][j+1][t] = max(dp[i][j+1][t], val);
                    }
                }
            }
        }
        
        return dp[n][m][k];
    }
};
