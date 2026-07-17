// @leetcode id=1537 questionId=1659 slug=get-the-maximum-score lang=cpp site=leetcode.com title="Get the Maximum Score"
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const long long MOD = 1e9 + 7;
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        long long sum1 = 0, sum2 = 0;
        long long total = 0;

        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                sum1 += nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                sum2 += nums2[j++];
            } else {
                total += max(sum1, sum2) + nums1[i];
                sum1 = 0;
                sum2 = 0;
                i++; j++;
            }
        }

        while (i < n1) sum1 += nums1[i++];
        while (j < n2) sum2 += nums2[j++];

        total += max(sum1, sum2);

        return (int)(total % MOD);
    }
};
