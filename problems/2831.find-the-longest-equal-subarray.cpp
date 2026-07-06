// @leetcode id=2831 questionId=2832 slug=find-the-longest-equal-subarray lang=cpp site=leetcode.com title="Find the Longest Equal Subarray"
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int left = 0, maxFreq = 0;

        for (int right = 0; right < n; ++right) {
            maxFreq = max(maxFreq, ++freq[nums[right]]);
            int windowLen = right - left + 1;
            if (windowLen - maxFreq > k) {
                --freq[nums[left]];
                ++left;
            }
        }
        return maxFreq;
    }
};
