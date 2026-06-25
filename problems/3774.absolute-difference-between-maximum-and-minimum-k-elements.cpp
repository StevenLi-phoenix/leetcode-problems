// @leetcode id=3774 questionId=4158 slug=absolute-difference-between-maximum-and-minimum-k-elements lang=cpp site=leetcode.com title="Absolute Difference Between Maximum and Minimum K Elements"
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int sumLargest = 0;
        int n = nums.size();
        for (int i = n - k; i < n; i++) {
            sumLargest += nums[i];
        }

        int sumSmallest = 0;
        for (int i = 0; i < k; i++) {
            sumSmallest += nums[i];
        }

        return abs(sumLargest - sumSmallest);
    }
};
