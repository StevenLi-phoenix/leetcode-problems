// @leetcode id=3430 questionId=3725 slug=maximum-and-minimum-sums-of-at-most-size-k-subarrays lang=cpp site=leetcode.com title="Maximum and Minimum Sums of at Most Size K Subarrays"
class Solution {
public:
    long long f(long long t) {
        if (t < 0) return 0;
        return (t + 1) * (t + 2) / 2;
    }

    long long countPairs(long long A, long long B, long long m) {
        return f(m) - f(m - A - 1) - f(m - B - 1) + f(m - A - B - 2);
    }

    long long sumWithExtreme(vector<int>& nums, int k, bool isMax) {
        int n = nums.size();
        long long m = k - 1;
        vector<int> left(n), right(n);
        vector<int> stk;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && (isMax ? nums[stk.back()] < nums[i] : nums[stk.back()] > nums[i])) {
                stk.pop_back();
            }
            left[i] = stk.empty() ? -1 : stk.back();
            stk.push_back(i);
        }
        stk.clear();

        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && (isMax ? nums[stk.back()] <= nums[i] : nums[stk.back()] >= nums[i])) {
                stk.pop_back();
            }
            right[i] = stk.empty() ? n : stk.back();
            stk.push_back(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long A = (long long)(i - left[i]) - 1;
            long long B = (long long)(right[i] - i) - 1;
            long long cnt = countPairs(A, B, m);
            total += (long long)nums[i] * cnt;
        }
        return total;
    }

    long long minMaxSubarraySum(vector<int>& nums, int k) {
        return sumWithExtreme(nums, k, true) + sumWithExtreme(nums, k, false);
    }
};
