// @leetcode id=2499 questionId=2592 slug=minimum-total-cost-to-make-arrays-unequal lang=cpp site=leetcode.com title="Minimum Total Cost to Make Arrays Unequal"
class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> count(n + 1, 0);
        long long sumBad = 0;
        int lenBad = 0, maxCount = 0, maxVal = 0;

        vector<bool> isBad(n, false);
        for (int i = 0; i < n; i++) {
            if (nums1[i] == nums2[i]) {
                isBad[i] = true;
                sumBad += i;
                lenBad++;
                count[nums1[i]]++;
                if (count[nums1[i]] > maxCount) { maxCount = count[nums1[i]]; maxVal = nums1[i]; }
            }
        }

        if (lenBad == 0) return 0;

        long long ans = sumBad;
        if (2 * maxCount > lenBad) {
            bool fixed = false;
            for (int i = 0; i < n && !fixed; i++) {
                if (isBad[i]) continue;
                if (nums1[i] == maxVal || nums2[i] == maxVal) continue;
                ans += i;
                lenBad++;
                if (2 * maxCount <= lenBad) fixed = true;
            }
            if (!fixed) return -1;
        }
        return ans;
    }
};
