// @leetcode id=1330 questionId=1255 slug=reverse-subarray-to-maximize-array-value lang=cpp site=leetcode.com title="Reverse Subarray To Maximize Array Value"
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int i = 0; i + 1 < n; i++) total += abs(nums[i] - nums[i + 1]);

        long long best = total;

        for (int i = 0; i + 1 < n; i++) {
            long long cand = total - abs(nums[i] - nums[i + 1]) + abs(nums[0] - nums[i + 1]);
            best = max(best, cand);
            cand = total - abs(nums[i] - nums[i + 1]) + abs(nums[n - 1] - nums[i]);
            best = max(best, cand);
        }

        long long maxLo = LLONG_MIN, minHi = LLONG_MAX;
        for (int i = 0; i + 1 < n; i++) {
            long long lo = min(nums[i], nums[i + 1]);
            long long hi = max(nums[i], nums[i + 1]);
            maxLo = max(maxLo, lo);
            minHi = min(minHi, hi);
        }
        best = max(best, total + max(0LL, 2 * (maxLo - minHi)));

        return (int)best;
    }
};
