// @leetcode id=3599 questionId=3913 slug=partition-array-to-minimize-xor lang=cpp site=leetcode.com title="Partition Array to Minimize XOR"
class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] ^ nums[i];

        const int INF = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = j; i <= n; i++) {
                for (int m = j - 1; m < i; m++) {
                    if (dp[m][j - 1] == INF) continue;
                    int segXor = pre[i] ^ pre[m];
                    int candidate = max(dp[m][j - 1], segXor);
                    dp[i][j] = min(dp[i][j], candidate);
                }
            }
        }
        return dp[n][k];
    }
};
