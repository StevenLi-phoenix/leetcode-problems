// @leetcode id=3473 questionId=3722 slug=sum-of-k-subarrays-with-length-at-least-m lang=cpp site=leetcode.com title="Sum of K Subarrays With Length at Least M"
class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        const long long NEG = LLONG_MIN / 2;
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, NEG));
        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        for (int j = 1; j <= k; j++) {
            long long runningMax = NEG;
            for (int i = 0; i <= n; i++) {
                int xIdx = i - m;
                if (xIdx >= 0 && dp[xIdx][j - 1] > NEG / 2) {
                    runningMax = max(runningMax, dp[xIdx][j - 1] - prefix[xIdx]);
                }
                long long option1 = (i >= 1) ? dp[i - 1][j] : NEG;
                long long option2 = (runningMax > NEG / 2) ? prefix[i] + runningMax : NEG;
                dp[i][j] = max(option1, option2);
            }
        }
        return (int)dp[n][k];
    }
};
