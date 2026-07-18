// @leetcode id=600 questionId=600 slug=non-negative-integers-without-consecutive-ones lang=cpp site=leetcode.com title="Non-negative Integers without Consecutive Ones"
class Solution {
public:
    int findIntegers(int n) {
        int fib[32];
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i < 32; i++) fib[i] = fib[i - 1] + fib[i - 2];

        int bits[32];
        int len = 0;
        for (int i = 31; i >= 0; i--) {
            bits[len++] = (n >> i) & 1;
        }

        int ans = 0;
        int prevBit = 0;
        bool hasConsecutive = false;

        for (int i = 0; i < len; i++) {
            if (bits[i] == 1) {
                ans += fib[len - i - 1];
                if (prevBit == 1) {
                    hasConsecutive = true;
                    break;
                }
            }
            prevBit = bits[i];
        }

        if (!hasConsecutive) ans++;

        return ans;
    }
};
