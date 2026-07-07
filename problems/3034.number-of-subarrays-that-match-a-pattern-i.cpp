// @leetcode id=3034 questionId=3269 slug=number-of-subarrays-that-match-a-pattern-i lang=cpp site=leetcode.com title="Number of Subarrays That Match a Pattern I"
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        int count = 0;

        for (int i = 0; i + m < n; ++i) {
            bool ok = true;
            for (int k = 0; k < m; ++k) {
                int diff = nums[i + k + 1] - nums[i + k];
                int sign = (diff > 0) ? 1 : (diff < 0 ? -1 : 0);
                if (sign != pattern[k]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ++count;
        }
        return count;
    }
};
