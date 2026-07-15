// @leetcode id=3818 questionId=4199 slug=minimum-prefix-removal-to-make-array-strictly-increasing lang=cpp site=leetcode.com title="Minimum Prefix Removal to Make Array Strictly Increasing"
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int start = n - 1;
        while (start > 0 && nums[start - 1] < nums[start]) start--;
        return start;
    }
};
