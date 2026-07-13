// @leetcode id=3940 questionId=4312 slug=limit-occurrences-in-sorted-array lang=cpp site=leetcode.com title="Limit Occurrences in Sorted Array"
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> result;
        int count = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) count++;
            else count = 1;
            if (count <= k) result.push_back(nums[i]);
        }
        return result;
    }
};
