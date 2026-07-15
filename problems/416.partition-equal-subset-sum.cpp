// @leetcode id=416 questionId=416 slug=partition-equal-subset-sum lang=cpp site=leetcode.com title="Partition Equal Subset Sum"
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int n : nums) total += n;
        if (total % 2 != 0) return false;
        int target = total / 2;

        bitset<20001> dp;
        dp[0] = 1;
        for (int n : nums) {
            dp |= dp << n;
        }
        return dp[target];
    }
};
