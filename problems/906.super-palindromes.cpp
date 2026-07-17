// @leetcode id=906 questionId=942 slug=super-palindromes lang=cpp site=leetcode.com title="Super Palindromes"
class Solution {
public:
    bool isPalindrome(unsigned long long x) {
        unsigned long long rev = 0, orig = x;
        while (orig > 0) { rev = rev * 10 + orig % 10; orig /= 10; }
        return rev == x;
    }

    long long reverseDigits(long long x) {
        long long rev = 0;
        while (x > 0) { rev = rev * 10 + x % 10; x /= 10; }
        return rev;
    }

    int superpalindromesInRange(string left, string right) {
        unsigned long long L = stoull(left);
        unsigned long long R = stoull(right);
        int count = 0;

        for (int halfLen = 1; halfLen <= 5; halfLen++) {
            long long lo = 1, hi = 9;
            for (int i = 1; i < halfLen; i++) { lo *= 10; hi = hi * 10 + 9; }
            long long pow10 = 1;
            for (int i = 0; i < halfLen; i++) pow10 *= 10;

            for (long long half = lo; half <= hi; half++) {
                long long revFull = reverseDigits(half);
                long long revDropLast = reverseDigits(half / 10);

                long long roots[2] = { half * pow10 + revFull, half * (pow10 / 10) + revDropLast };

                for (int type = 0; type < 2; type++) {
                    unsigned long long r = (unsigned long long)roots[type];
                    unsigned __int128 sq = (unsigned __int128)r * r;
                    if (sq > (unsigned __int128)R) continue;

                    unsigned long long sqVal = (unsigned long long)sq;
                    if (sqVal >= L && sqVal <= R && isPalindrome(sqVal)) count++;
                }
            }
        }

        return count;
    }
};
