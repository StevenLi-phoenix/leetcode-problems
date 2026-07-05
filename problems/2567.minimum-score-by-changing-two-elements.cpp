// @leetcode id=2567 questionId=2706 slug=minimum-score-by-changing-two-elements lang=cpp site=leetcode.com title="Minimum Score by Changing Two Elements"
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int opt1 = nums[n - 1] - nums[2];
        int opt2 = nums[n - 3] - nums[0];
        int opt3 = nums[n - 2] - nums[1];
        return min({opt1, opt2, opt3});
    }
};
