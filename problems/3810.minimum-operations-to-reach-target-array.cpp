// @leetcode id=3810 questionId=4190 slug=minimum-operations-to-reach-target-array lang=cpp site=leetcode.com title="Minimum Operations to Reach Target Array"
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> distinctMismatched;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != target[i]) distinctMismatched.insert(nums[i]);
        }
        return (int)distinctMismatched.size();
    }
};
