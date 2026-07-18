// @leetcode id=1955 questionId=2086 slug=count-number-of-special-subsequences lang=cpp site=leetcode.com title="Count Number of Special Subsequences"
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        const long long MOD = 1000000007;
        long long dp0 = 0, dp1 = 0, dp2 = 0;

        for (int x : nums) {
            if (x == 0) {
                dp0 = (dp0 * 2 + 1) % MOD;
            } else if (x == 1) {
                dp1 = (dp1 * 2 + dp0) % MOD;
            } else {
                dp2 = (dp2 * 2 + dp1) % MOD;
            }
        }

        return (int)dp2;
    }
};
