// @leetcode id=2765 questionId=2870 slug=longest-alternating-subarray lang=cpp site=leetcode.com title="Longest Alternating Subarray"
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int best = -1;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int expectedDiff = 1;
            while (j < n && nums[j] - nums[j - 1] == expectedDiff) {
                j++;
                expectedDiff = -expectedDiff;
            }
            if (j - i > 1) best = max(best, j - i);
        }
        return best;
    }
};
