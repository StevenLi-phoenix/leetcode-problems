// @leetcode id=2514 questionId=2605 slug=count-anagrams lang=cpp site=leetcode.com title="Count Anagrams"
class Solution {
public:
    static const long long MOD = 1000000007;

    long long modpow(long long base, long long e, long long mod) {
        base %= mod;
        long long res = 1;
        while (e > 0) {
            if (e & 1) res = res * base % mod;
            base = base * base % mod;
            e >>= 1;
        }
        return res;
    }

    int countAnagrams(string s) {
        int n = s.size();
        vector<long long> fact(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;

        long long ans = 1;
        int i = 0;
        while (i < n) {
            int start = i;
            int cnt[26] = {0};
            while (i < n && s[i] != ' ') {
                cnt[s[i] - 'a']++;
                i++;
            }
            int len = i - start;
            long long denom = 1;
            for (int c = 0; c < 26; c++) denom = denom * fact[cnt[c]] % MOD;
            ans = ans * fact[len] % MOD * modpow(denom, MOD - 2, MOD) % MOD;
            if (i < n) i++; // skip space
        }

        return (int)ans;
    }
};
