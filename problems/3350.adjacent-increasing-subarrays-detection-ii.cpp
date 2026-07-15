// @leetcode id=3350 questionId=3619 slug=adjacent-increasing-subarrays-detection-ii lang=cpp site=leetcode.com title="Adjacent Increasing Subarrays Detection II"
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> backward(n), forward(n);
        backward[0] = 1;
        for (int i = 1; i < n; i++) {
            backward[i] = (nums[i] > nums[i - 1]) ? backward[i - 1] + 1 : 1;
        }
        forward[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            forward[i] = (nums[i] < nums[i + 1]) ? forward[i + 1] + 1 : 1;
        }

        int best = 0;
        for (int i = 0; i + 1 < n; i++) {
            best = max(best, min(backward[i], forward[i + 1]));
        }
        return best;
    }
};
