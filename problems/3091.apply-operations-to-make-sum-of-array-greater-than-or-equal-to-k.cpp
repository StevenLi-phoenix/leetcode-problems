// @leetcode id=3091 questionId=3328 slug=apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k lang=cpp site=leetcode.com title="Apply Operations to Make Sum of Array Greater Than or Equal to k"
class Solution {
public:
    int minOperations(int k) {
        if (k == 1) return 0;

        int minOps = INT_MAX;

        for (int m = 1; m <= k; m++) {
            int increases = m - 1;
            int copies_needed = (k + m - 1) / m;
            int duplicates = copies_needed - 1;
            int total = increases + duplicates;
            minOps = min(minOps, total);

            if (m * m >= k) break;
        }

        return minOps;
    }
};
