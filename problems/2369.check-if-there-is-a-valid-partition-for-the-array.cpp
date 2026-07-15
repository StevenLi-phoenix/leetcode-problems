// @leetcode id=2369 questionId=2443 slug=check-if-there-is-a-valid-partition-for-the-array lang=cpp site=leetcode.com title="Check if There is a Valid Partition For The Array"
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 2; i <= n; i++) {
            if (dp[i - 2] && nums[i - 1] == nums[i - 2]) dp[i] = true;
            if (!dp[i] && i >= 3 && dp[i - 3]) {
                if (nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3]) dp[i] = true;
                else if (nums[i - 1] == nums[i - 2] + 1 && nums[i - 2] == nums[i - 3] + 1) dp[i] = true;
            }
        }
        return dp[n];
    }
};
