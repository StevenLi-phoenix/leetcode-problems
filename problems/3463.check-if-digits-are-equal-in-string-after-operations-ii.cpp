// @leetcode id=3463 questionId=3774 slug=check-if-digits-are-equal-in-string-after-operations-ii lang=cpp site=leetcode.com title="Check If Digits Are Equal in String After Operations II"
class Solution {
public:
    int nCr5[5][5];

    int cMod2(long long m, long long k) {
        return ((k & m) == k) ? 1 : 0;
    }

    int cMod5(long long m, long long k) {
        if (k > m) return 0;
        long long res = 1;
        while (m > 0 || k > 0) {
            int mi = m % 5, ki = k % 5;
            if (ki > mi) return 0;
            res = (res * nCr5[mi][ki]) % 5;
            m /= 5;
            k /= 5;
        }
        return (int)res;
    }

    bool hasSameDigits(string s) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) nCr5[i][j] = 0;
            nCr5[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                int prev = (i - 1 >= 0) ? nCr5[i - 1][j - 1] : 0;
                int prev2 = (i - 1 >= 0 && j <= i - 1) ? nCr5[i - 1][j] : 0;
                nCr5[i][j] = (prev + prev2) % 5;
            }
        }

        int n = s.size();
        long long m = n - 2;

        int sumA2 = 0, sumA5 = 0, sumB2 = 0, sumB5 = 0;
        for (int k = 0; k <= m; k++) {
            int c2 = cMod2(m, k);
            int c5 = cMod5(m, k);
            int dA = s[k] - '0';
            sumA2 = (sumA2 + c2 * (dA % 2)) % 2;
            sumA5 = (sumA5 + c5 * (dA % 5)) % 5;
            int dB = s[k + 1] - '0';
            sumB2 = (sumB2 + c2 * (dB % 2)) % 2;
            sumB5 = (sumB5 + c5 * (dB % 5)) % 5;
        }

        int digitA = -1, digitB = -1;
        for (int x = 0; x < 10; x++) {
            if (x % 2 == sumA2 && x % 5 == sumA5) digitA = x;
            if (x % 2 == sumB2 && x % 5 == sumB5) digitB = x;
        }

        return digitA == digitB;
    }
};
