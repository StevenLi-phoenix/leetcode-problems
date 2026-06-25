// @leetcode id=2401 questionId=2478 slug=longest-nice-subarray lang=cpp site=leetcode.com title="Longest Nice Subarray"
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        long long current_or = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            while ((current_or & nums[right]) != 0) {
                current_or ^= nums[left];
                left++;
            }

            current_or |= nums[right];
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
