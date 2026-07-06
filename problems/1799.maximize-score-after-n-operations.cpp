// @leetcode id=1799 questionId=1906 slug=maximize-score-after-n-operations lang=cpp site=leetcode.com title="Maximize Score After N Operations"
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m = nums.size();
        vector<int> dp(1 << m, -1);
        dp[0] = 0;

        for (int mask = 1; mask < (1 << m); ++mask) {
            int bits = __builtin_popcount(mask);
            if (bits % 2 != 0) continue;
            int op = bits / 2;

            for (int j = 0; j < m; ++j) {
                if (!(mask & (1 << j))) continue;
                for (int i = 0; i < j; ++i) {
                    if (!(mask & (1 << i))) continue;
                    int prevMask = mask ^ (1 << i) ^ (1 << j);
                    if (dp[prevMask] < 0) continue;
                    int score = dp[prevMask] + op * (int)gcd(nums[i], nums[j]);
                    dp[mask] = max(dp[mask], score);
                }
            }
        }

        return dp[(1 << m) - 1];
    }
};
