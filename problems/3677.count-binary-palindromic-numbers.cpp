// @leetcode id=3677 questionId=4023 slug=count-binary-palindromic-numbers lang=cpp site=leetcode.com title="Count Binary Palindromic Numbers"
class Solution {
public:
    long long reverseBits(long long x, int len) {
        long long r = 0;
        for (int i = 0; i < len; i++) {
            r = (r << 1) | (x & 1);
            x >>= 1;
        }
        return r;
    }

    long long buildPalindrome(long long half, int halfLen, int totalLen) {
        // half occupies the high halfLen bits of the result (MSB-first value == half itself, since half's own
        // bit layout already represents MSB..LSB when read as an integer of halfLen bits)
        int tailLen = totalLen - halfLen;
        long long tail = reverseBits(half >> (totalLen % 2), tailLen);
        return (half << tailLen) | tail;
    }

    int countBinaryPalindromes(long long n) {
        if (n == 0) return 1;

        int bitLen = 0;
        {
            long long tmp = n;
            while (tmp > 0) { bitLen++; tmp >>= 1; }
        }

        long long count = 1; // for 0

        for (int L = 1; L < bitLen; L++) {
            int halfLen = (L + 1) / 2;
            count += (1LL << (halfLen - 1));
        }

        int halfLen = (bitLen + 1) / 2;
        long long start = (1LL << (halfLen - 1));
        long long end = (1LL << halfLen) - 1;

        // buildPalindrome(half) is monotonically increasing in half, so binary search the boundary
        long long lo = start - 1, hi = end;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (buildPalindrome(mid, halfLen, bitLen) <= n) lo = mid;
            else hi = mid - 1;
        }
        if (lo >= start) count += (lo - start + 1);

        return (int)count;
    }
};
