// @leetcode id=494 questionId=494 slug=target-sum lang=cpp site=leetcode.com title="Target Sum"
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (int num : nums) {
            unordered_map<int, int> next;
            for (auto& [sum, cnt] : dp) {
                next[sum + num] += cnt;
                next[sum - num] += cnt;
            }
            dp = next;
        }
        return dp.count(target) ? dp[target] : 0;
    }
};
