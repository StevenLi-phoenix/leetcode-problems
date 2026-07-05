// @leetcode id=3349 questionId=3612 slug=adjacent-increasing-subarrays-detection-i lang=cpp site=leetcode.com title="Adjacent Increasing Subarrays Detection I"
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        auto isIncreasing = [&](int start) {
            for (int i = start; i < start + k - 1; ++i) {
                if (nums[i] >= nums[i + 1]) return false;
            }
            return true;
        };

        for (int a = 0; a + 2 * k <= n; ++a) {
            if (isIncreasing(a) && isIncreasing(a + k)) return true;
        }
        return false;
    }
};
