// @leetcode id=1389 questionId=1505 slug=create-target-array-in-the-given-order lang=cpp site=leetcode.com title="Create Target Array in the Given Order"
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        for (int i = 0; i < nums.size(); i++) {
            target.insert(target.begin() + index[i], nums[i]);
        }
        return target;
    }
};
