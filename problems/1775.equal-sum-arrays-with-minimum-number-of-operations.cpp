// @leetcode id=1775 questionId=1901 slug=equal-sum-arrays-with-minimum-number-of-operations lang=cpp site=leetcode.com title="Equal Sum Arrays With Minimum Number of Operations"
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        for (int v : nums1) sum1 += v;
        for (int v : nums2) sum2 += v;
        if (sum1 == sum2) return 0;
        if (sum1 < sum2) { swap(nums1, nums2); swap(sum1, sum2); }

        long long diff = sum1 - sum2;
        vector<int> cnt(6, 0);
        for (int v : nums1) cnt[v - 1]++;
        for (int v : nums2) cnt[6 - v]++;

        int ops = 0;
        for (int g = 5; g >= 1 && diff > 0; --g) {
            while (cnt[g] > 0 && diff > 0) {
                diff -= g;
                --cnt[g];
                ++ops;
            }
        }
        return diff <= 0 ? ops : -1;
    }
};
