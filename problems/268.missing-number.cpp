// @leetcode id=268 questionId=268 slug=missing-number lang=cpp site=leetcode.com title="Missing Number"
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int i = 0; i < (int)nums.size(); i++) result ^= i ^ nums[i];
        return result;
    }
};
