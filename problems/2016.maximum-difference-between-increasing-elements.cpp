// @leetcode id=2016 questionId=2144 slug=maximum-difference-between-increasing-elements lang=cpp site=leetcode.com title="Maximum Difference Between Increasing Elements"
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int minVal = nums[0];
        for (int j = 1; j < (int)nums.size(); ++j) {
            if (nums[j] > minVal) ans = max(ans, nums[j] - minVal);
            else minVal = nums[j];
        }
        return ans;
    }
};
