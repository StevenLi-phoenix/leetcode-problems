// @leetcode id=3082 questionId=3345 slug=find-the-sum-of-the-power-of-all-subsequences lang=cpp site=leetcode.com title="Find the Sum of the Power of All Subsequences"
class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        // Swap the order of summation: instead of summing, over every
        // subsequence A, the count of sub-subsequences B with sum k, sum
        // over every subsequence B with sum k the number of supersets A it
        // has (2^(n - |B|), freely including/excluding the other elements).
        const long long MOD = 1'000'000'007;
        int n = nums.size();
        // dp[j][s] = number of size-j subsets with sum s.
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        dp[0][0] = 1;
        for (int x : nums) {
            for (int j = n - 1; j >= 0; j--) {
                for (int s = k; s >= x; s--) {
                    dp[j + 1][s] = (dp[j + 1][s] + dp[j][s - x]) % MOD;
                }
            }
        }

        vector<long long> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) pow2[i] = pow2[i - 1] * 2 % MOD;

        long long ans = 0;
        for (int j = 0; j <= n; j++) ans = (ans + dp[j][k] * pow2[n - j]) % MOD;
        return (int)ans;
    }
};
