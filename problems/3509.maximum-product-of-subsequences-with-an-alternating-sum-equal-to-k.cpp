// @leetcode id=3509 questionId=3777 slug=maximum-product-of-subsequences-with-an-alternating-sum-equal-to-k lang=cpp site=leetcode.com title="Maximum Product of Subsequences With an Alternating Sum Equal to K"
class Solution {
public:
    static const int OFFSET = 1800; // |alternating sum| <= 12 * 150
    static const int SZ = 2 * OFFSET + 1;

    int maxProduct(vector<int>& nums, int k, int limit) {
        if (k < -OFFSET || k > OFFSET) return -1;

        // real[parity][product] = bitset of alternating sums (offset)
        // reachable by a NON-EMPTY subsequence with that exact product
        // (<=limit) so far; parity is the sign the NEXT appended element
        // would get (0 => +, 1 => -). Keeping only the *best* product per
        // (parity,sum) is wrong: a smaller product now can survive a later
        // multiplication that would push the "best" one over the limit. So
        // track the full reachable set per product value instead, using
        // bitset shifts (by x) to move sums efficiently.
        // cap[parity] = sums reachable only via a product that already
        // exceeds limit; useless directly, but a future 0 resets ANY
        // product (real or capped) to exactly 0, so it must still be
        // tracked.
        vector<vector<bitset<SZ>>> real(2, vector<bitset<SZ>>(limit + 1));
        bitset<SZ> cap[2];

        for (int x : nums) {
            vector<vector<bitset<SZ>>> newReal(2, vector<bitset<SZ>>(limit + 1));
            bitset<SZ> newCap[2];

            // Start a fresh subsequence with just this element.
            int freshSum = OFFSET + x;
            if (freshSum >= 0 && freshSum < SZ) {
                if (x == 0) newReal[1][0].set(freshSum);
                else if (x <= limit) newReal[1][x].set(freshSum);
                else newCap[1].set(freshSum);
            }

            for (int p = 0; p < 2; p++) {
                int np = 1 - p;
                if (x == 0) {
                    // Any existing state, real or capped, becomes exactly
                    // product 0; sum is unchanged (0 contributes nothing).
                    for (int prod = 0; prod <= limit; prod++) newReal[np][0] |= real[p][prod];
                    newReal[np][0] |= cap[p];
                } else {
                    bool shiftUp = (p == 0); // parity0 source contributes +x to sum
                    newCap[np] |= shiftUp ? (cap[p] << x) : (cap[p] >> x);
                    for (int prod = 0; prod <= limit; prod++) {
                        if (real[p][prod].none()) continue;
                        long long newProd = (long long)prod * x;
                        bitset<SZ> shifted = shiftUp ? (real[p][prod] << x) : (real[p][prod] >> x);
                        if (newProd <= limit) newReal[np][(int)newProd] |= shifted;
                        else newCap[np] |= shifted;
                    }
                }
            }

            for (int p = 0; p < 2; p++) {
                for (int prod = 0; prod <= limit; prod++) real[p][prod] |= newReal[p][prod];
                cap[p] |= newCap[p];
            }
        }

        int target = k + OFFSET;
        for (int prod = limit; prod >= 0; prod--)
            if (real[0][prod].test(target) || real[1][prod].test(target)) return prod;
        return -1;
    }
};
