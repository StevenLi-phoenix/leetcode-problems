// @leetcode id=801 questionId=819 slug=minimum-swaps-to-make-sequences-increasing lang=cpp site=leetcode.com title="Minimum Swaps To Make Sequences Increasing"
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int keep = 0, swap_ = 1;

        for (int i = 1; i < n; i++) {
            int newKeep = INT_MAX, newSwap = INT_MAX;

            if (nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]) {
                newKeep = min(newKeep, keep);
                newSwap = min(newSwap, swap_ + 1);
            }
            if (nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) {
                newKeep = min(newKeep, swap_);
                newSwap = min(newSwap, keep + 1);
            }

            keep = newKeep;
            swap_ = newSwap;
        }

        return min(keep, swap_);
    }
};
