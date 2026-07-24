// @leetcode id=2970 questionId=3252 slug=count-the-number-of-incremovable-subarrays-i lang=cpp site=leetcode.com title="Count the Number of Incremovable Subarrays I"
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                vector<int> remaining;
                for (int i = 0; i < l; i++) remaining.push_back(nums[i]);
                for (int i = r + 1; i < n; i++) remaining.push_back(nums[i]);

                bool increasing = true;
                for (int i = 1; i < (int)remaining.size(); i++) {
                    if (remaining[i] <= remaining[i - 1]) { increasing = false; break; }
                }
                if (increasing) count++;
            }
        }
        return count;
    }
};
