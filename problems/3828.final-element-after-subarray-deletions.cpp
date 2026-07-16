// @leetcode id=3828 questionId=4122 slug=final-element-after-subarray-deletions lang=cpp site=leetcode.com title="Final Element After Subarray Deletions"
class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(), nums.back());
    }
};
