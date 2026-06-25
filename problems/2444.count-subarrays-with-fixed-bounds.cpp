// @leetcode id=2444 questionId=2527 slug=count-subarrays-with-fixed-bounds lang=cpp site=leetcode.com title="Count Subarrays With Fixed Bounds"
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int lastBad = -1, lastMin = -1, lastMax = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) lastBad = i;
            if (nums[i] == minK) lastMin = i;
            if (nums[i] == maxK) lastMax = i;
            long long valid = min(lastMin, lastMax) - lastBad;
            if (valid > 0) ans += valid;
        }
        return ans;
    }
};
