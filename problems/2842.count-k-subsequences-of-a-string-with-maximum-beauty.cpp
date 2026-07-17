// @leetcode id=2842 questionId=3057 slug=count-k-subsequences-of-a-string-with-maximum-beauty lang=cpp site=leetcode.com title="Count K-Subsequences of a String With Maximum Beauty"
class Solution {
public:
    static const long long MOD = 1000000007;

    long long modpow(long long base, long long exp, long long mod) {
        base %= mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        long long num = 1, den = 1;
        for (int i = 0; i < r; i++) {
            num = num * (n - i) % MOD;
            den = den * (i + 1) % MOD;
        }
        return num * modpow(den, MOD - 2, MOD) % MOD;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> freqs;
        for (int f : freq) if (f > 0) freqs.push_back(f);

        if ((int)freqs.size() < k) return 0;

        sort(freqs.rbegin(), freqs.rend());
        int threshold = freqs[k - 1];

        int m = 0;
        long long forcedProduct = 1;
        for (int f : freqs) {
            if (f > threshold) {
                m++;
                forcedProduct = forcedProduct * f % MOD;
            }
        }

        int cnt = 0;
        for (int f : freqs) if (f == threshold) cnt++;

        int need = k - m;
        long long ways = nCr(cnt, need);
        long long thresholdPow = modpow(threshold, need, MOD);

        long long answer = forcedProduct * ways % MOD * thresholdPow % MOD;
        return (int)answer;
    }
};
