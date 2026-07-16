// @leetcode id=2918 questionId=3171 slug=minimum-equal-sum-of-two-arrays-after-replacing-zeros lang=cpp site=leetcode.com title="Minimum Equal Sum of Two Arrays After Replacing Zeros"
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zeros1 = 0, zeros2 = 0;
        for (int x : nums1) { sum1 += x; if (x == 0) zeros1++; }
        for (int x : nums2) { sum2 += x; if (x == 0) zeros2++; }

        long long minSum1 = sum1 + zeros1;
        long long minSum2 = sum2 + zeros2;

        if (zeros1 == 0 && minSum1 < minSum2) return -1;
        if (zeros2 == 0 && minSum2 < minSum1) return -1;

        return max(minSum1, minSum2);
    }
};
