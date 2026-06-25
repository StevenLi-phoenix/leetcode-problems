// @leetcode id=2760 questionId=2866 slug=longest-even-odd-subarray-with-threshold lang=cpp site=leetcode.com title="Longest Even Odd Subarray With Threshold"
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxLen = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                int len = 1;
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] <= threshold && nums[j] % 2 != nums[j-1] % 2) {
                        len++;
                    } else {
                        break;
                    }
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};
