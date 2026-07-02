// @leetcode id=1043 questionId=1121 slug=partition-array-for-maximum-sum lang=cpp site=leetcode.com title="Partition Array for Maximum Sum"
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int maxVal = 0;
            for (int len = 1; len <= k && len <= i; len++) {
                maxVal = max(maxVal, arr[i - len]);
                dp[i] = max(dp[i], dp[i - len] + maxVal * len);
            }
        }
        return dp[n];
    }
};
