// @leetcode id=3452 questionId=3723 slug=sum-of-good-numbers lang=cpp site=leetcode.com title="Sum of Good Numbers"
class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            bool good = true;
            if (i - k >= 0 && nums[i] <= nums[i - k]) good = false;
            if (i + k < n && nums[i] <= nums[i + k]) good = false;
            if (good) total += nums[i];
        }
        return total;
    }
};
