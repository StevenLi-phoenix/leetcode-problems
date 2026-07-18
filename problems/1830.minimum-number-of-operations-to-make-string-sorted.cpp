// @leetcode id=1830 questionId=1941 slug=minimum-number-of-operations-to-make-string-sorted lang=cpp site=leetcode.com title="Minimum Number of Operations to Make String Sorted"
class Solution {
public:
    static const long long MOD = 1000000007;

    long long modpow(long long b, long long e, long long m) {
        b %= m;
        long long r = 1;
        while (e > 0) {
            if (e & 1) r = r * b % m;
            b = b * b % m;
            e >>= 1;
        }
        return r;
    }

    int makeStringSorted(string s) {
        int n = s.size();

        bool sorted = true;
        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) { sorted = false; break; }
        }
        if (sorted) return 0;

        vector<long long> fact(n + 1, 1), invFact(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        invFact[n] = modpow(fact[n], MOD - 2, MOD);
        for (int i = n; i > 0; i--) invFact[i - 1] = invFact[i] * i % MOD;

        int counts[26] = {0};
        for (char c : s) counts[c - 'a']++;

        long long rank = 0;
        for (int i = 0; i < n; i++) {
            int remaining = n - i - 1;
            int ci = s[i] - 'a';
            for (int c = 0; c < ci; c++) {
                if (counts[c] == 0) continue;
                counts[c]--;
                long long denomInv = 1;
                for (int d = 0; d < 26; d++) denomInv = denomInv * invFact[counts[d]] % MOD;
                long long perms = fact[remaining] * denomInv % MOD;
                rank = (rank + perms) % MOD;
                counts[c]++;
            }
            counts[ci]--;
        }

        return (int)rank;
    }
};
