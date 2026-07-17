// @leetcode id=3347 questionId=3640 slug=maximum-frequency-of-an-element-after-performing-operations-ii lang=cpp site=leetcode.com title="Maximum Frequency of an Element After Performing Operations II"
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long best = 0;
        int left = 0, right = 0;

        for (int i = 0; i < n; i++) {
            while (right < n && (long long)nums[right] - nums[i] <= k) right++;
            while ((long long)nums[i] - nums[left] > k) left++;

            long long windowCount = right - left;

            auto range = equal_range(nums.begin(), nums.end(), nums[i]);
            long long freqEqual = range.second - range.first;

            long long candidate = min(windowCount, freqEqual + (long long)numOperations);
            best = max(best, candidate);
        }

        // arbitrary target not aligned with any existing value: window of width 2k,
        // no free "already equal" bonus, capped purely by numOperations
        int r2 = 0;
        for (int i = 0; i < n; i++) {
            while (r2 < n && (long long)nums[r2] - nums[i] <= 2LL * k) r2++;
            long long windowCount2 = r2 - i;
            best = max(best, min(windowCount2, (long long)numOperations));
        }

        return (int)best;
    }
};
