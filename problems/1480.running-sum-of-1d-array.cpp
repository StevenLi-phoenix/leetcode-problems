// @leetcode id=1480 questionId=1603 slug=running-sum-of-1d-array lang=cpp site=leetcode.com title="Running Sum of 1d Array"
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < (int)nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
