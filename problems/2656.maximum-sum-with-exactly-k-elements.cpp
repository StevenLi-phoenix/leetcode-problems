// @leetcode id=2656 questionId=2767 slug=maximum-sum-with-exactly-k-elements lang=cpp site=leetcode.com title="Maximum Sum With Exactly K Elements "
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        return k * maxVal + k * (k - 1) / 2;
    }
};
