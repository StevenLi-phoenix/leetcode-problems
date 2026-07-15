// @leetcode id=2541 questionId=2604 slug=minimum-operations-to-make-array-equal-ii lang=cpp site=leetcode.com title="Minimum Operations to Make Array Equal II"
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long positiveSum = 0;
        long long totalDiff = 0;

        for (size_t i = 0; i < nums1.size(); i++) {
            long long diff = (long long)nums2[i] - nums1[i];
            totalDiff += diff;
            if (k == 0) {
                if (diff != 0) return -1;
            } else {
                if (diff % k != 0) return -1;
                if (diff > 0) positiveSum += diff / k;
            }
        }

        if (totalDiff != 0) return -1;
        return k == 0 ? 0 : positiveSum;
    }
};
