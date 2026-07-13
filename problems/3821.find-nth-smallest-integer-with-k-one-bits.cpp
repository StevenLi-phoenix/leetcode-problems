// @leetcode id=3821 questionId=4189 slug=find-nth-smallest-integer-with-k-one-bits lang=cpp site=leetcode.com title="Find Nth Smallest Integer With K One Bits"
class Solution {
public:
    long long nthSmallest(long long n, int k) {
        // Build the answer bit by bit from the highest position down. At
        // each position, C(remaining_lower_bits, ones_still_needed) counts
        // how many valid numbers share the prefix built so far with this
        // bit set to 0; if n exceeds that count, this bit must be 1.
        static long long C[60][60];
        static bool init = false;
        if (!init) {
            for (int i = 0; i < 60; i++) {
                C[i][0] = 1;
                for (int j = 1; j <= i; j++) {
                    C[i][j] = C[i - 1][j - 1] + (j <= i - 1 ? C[i - 1][j] : 0);
                }
            }
            init = true;
        }

        long long result = 0;
        int need = k;
        for (int pos = 49; pos >= 0; pos--) {
            long long ways = (need >= 0 && need <= pos) ? C[pos][need] : 0;
            if (n > ways) {
                n -= ways;
                result |= (1LL << pos);
                need--;
            }
        }
        return result;
    }
};
