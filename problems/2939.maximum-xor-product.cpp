// @leetcode id=2939 questionId=3192 slug=maximum-xor-product lang=cpp site=leetcode.com title="Maximum Xor Product"
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        // XOR with x flips bit i of both a and b simultaneously. When their
        // bits already agree, forcing both to 1 only helps. When they
        // differ, x can freely choose which of the two gets the 1 (since
        // both (a_i,b_i) and (1-a_i,1-b_i) are reachable) — give it to
        // whichever is currently smaller, to keep them balanced (maximizing
        // a product for a roughly fixed total favors closeness).
        const long long MOD = 1'000'000'007;
        for (int i = n - 1; i >= 0; i--) {
            int abit = (a >> i) & 1, bbit = (b >> i) & 1;
            long long bit = 1LL << i;
            if (abit == bbit) {
                if (abit == 0) { a |= bit; b |= bit; }
            } else {
                if (a < b) { a |= bit; b &= ~bit; }
                else { b |= bit; a &= ~bit; }
            }
        }
        return (int)((a % MOD) * (b % MOD) % MOD);
    }
};
