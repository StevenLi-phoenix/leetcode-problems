// @leetcode id=2089 questionId=2210 slug=find-target-indices-after-sorting-array lang=cpp site=leetcode.com title="Find Target Indices After Sorting Array"
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less_count = 0, equal_count = 0;
        for (int x : nums) {
            if (x < target) less_count++;
            else if (x == target) equal_count++;
        }
        vector<int> result;
        for (int i = 0; i < equal_count; i++) {
            result.push_back(less_count + i);
        }
        return result;
    }
};
