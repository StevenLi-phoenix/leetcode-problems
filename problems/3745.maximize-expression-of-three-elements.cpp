// @leetcode id=3745 questionId=4112 slug=maximize-expression-of-three-elements lang=cpp site=leetcode.com title="Maximize Expression of Three Elements"
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - 1] + nums[n - 2] - nums[0];
    }
};
