// @leetcode id=2321 questionId=1348 slug=maximum-score-of-spliced-array lang=cpp site=leetcode.com title="Maximum Score Of Spliced Array"
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
        }
        
        // Kadane's on (nums2 - nums1)
        auto kadane = [](vector<int>& a, vector<int>& b) {
            int n = a.size();
            int maxGain = 0, curGain = 0;
            for (int i = 0; i < n; i++) {
                curGain = max(0, curGain + b[i] - a[i]);
                maxGain = max(maxGain, curGain);
            }
            return maxGain;
        };
        
        int gain1 = kadane(nums1, nums2); // swap from nums2 to nums1
        int gain2 = kadane(nums2, nums1); // swap from nums1 to nums2
        
        return max(sum1 + gain1, sum2 + gain2);
    }
};
