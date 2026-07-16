// @leetcode id=3670 questionId=3915 slug=maximum-product-of-two-integers-with-no-common-bits lang=cpp site=leetcode.com title="Maximum Product of Two Integers With No Common Bits"
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int maxVal = 0;
        for (int x : nums) maxVal = max(maxVal, x);

        int BITS = 1;
        while ((1 << BITS) <= maxVal) BITS++;
        const int SIZE = 1 << BITS;
        const int FULL = SIZE - 1;

        vector<int> subsetMax(SIZE, 0);
        for (int x : nums) {
            subsetMax[x] = max(subsetMax[x], x);
        }

        for (int b = 0; b < BITS; b++) {
            for (int mask = 0; mask < SIZE; mask++) {
                if (mask & (1 << b)) {
                    subsetMax[mask] = max(subsetMax[mask], subsetMax[mask ^ (1 << b)]);
                }
            }
        }

        long long best = 0;
        for (int x : nums) {
            int complement = FULL ^ x;
            int partner = subsetMax[complement];
            if (partner > 0) {
                best = max(best, (long long)x * partner);
            }
        }
        return best;
    }
};
