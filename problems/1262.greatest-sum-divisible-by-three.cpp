// @leetcode id=1262 questionId=1388 slug=greatest-sum-divisible-by-three lang=cpp site=leetcode.com title="Greatest Sum Divisible by Three"
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[r] = max sum achievable with remainder r
        vector<long long> dp(3, 0);
        dp[1] = dp[2] = LLONG_MIN;

        for (int n : nums) {
            vector<long long> ndp = dp;
            for (int r = 0; r < 3; r++) {
                if (dp[r] == LLONG_MIN) continue;
                int nr = (r + n) % 3;
                ndp[nr] = max(ndp[nr], dp[r] + n);
            }
            dp = ndp;
        }
        return (int)dp[0];
    }
};
