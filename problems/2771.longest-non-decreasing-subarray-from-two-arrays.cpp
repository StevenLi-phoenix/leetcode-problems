// @leetcode id=2771 questionId=2869 slug=longest-non-decreasing-subarray-from-two-arrays lang=cpp site=leetcode.com title="Longest Non-decreasing Subarray From Two Arrays"
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> dp1(n, 1), dp2(n, 1);
        int best = 1;
        for (int i = 1; i < n; i++) {
            if (nums1[i - 1] <= nums1[i]) dp1[i] = max(dp1[i], dp1[i - 1] + 1);
            if (nums2[i - 1] <= nums1[i]) dp1[i] = max(dp1[i], dp2[i - 1] + 1);

            if (nums1[i - 1] <= nums2[i]) dp2[i] = max(dp2[i], dp1[i - 1] + 1);
            if (nums2[i - 1] <= nums2[i]) dp2[i] = max(dp2[i], dp2[i - 1] + 1);

            best = max({best, dp1[i], dp2[i]});
        }
        return best;
    }
};
