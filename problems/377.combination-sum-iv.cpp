// @leetcode id=377 questionId=377 slug=combination-sum-iv lang=cpp site=leetcode.com title="Combination Sum IV"
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int t = 1; t <= target; t++) {
            for (int n : nums) {
                if (n <= t) dp[t] += dp[t - n];
            }
        }
        return (int)dp[target];
    }
};
