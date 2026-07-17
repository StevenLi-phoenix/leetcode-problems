// @leetcode id=2851 questionId=3024 slug=string-transformation lang=cpp site=leetcode.com title="String Transformation"
class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modpow(long long base, long long exp, long long mod) {
        base %= mod;
        if (base < 0) base += mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    int numberOfWays(string s, string t, long long k) {
        int n = s.size();

        // KMP: find all rotation shifts r in [0,n-1] such that rotate(s,r) == t
        string text = s + s;
        string pattern = t + "#" + text;
        int m = pattern.size();
        vector<int> fail(m, 0);
        for (int i = 1; i < m; i++) {
            int j = fail[i - 1];
            while (j > 0 && pattern[i] != pattern[j]) j = fail[j - 1];
            if (pattern[i] == pattern[j]) j++;
            fail[i] = j;
        }

        int goodTotal = 0;
        bool zeroGood = false;
        for (int i = t.size() + 1; i < m; i++) {
            if (fail[i] == (int)t.size()) {
                int matchEnd = i - (t.size() + 1); // index in `text` (0-indexed) of match end
                int start = matchEnd - n + 1;
                if (start >= 0 && start <= n - 1) {
                    goodTotal++;
                    if (start == 0) zeroGood = true;
                }
            }
        }

        long long invN = modpow(n, MOD - 2, MOD);
        long long sign = (k % 2 == 0) ? 1 : MOD - 1; // (-1)^k

        long long pw = modpow(n - 1, k, MOD);

        long long e_k = (pw + sign * (n - 1)) % MOD * invN % MOD;
        long long signOpp = (k % 2 == 0) ? MOD - 1 : 1; // (-1)^(k+1)
        long long o_k = (pw + signOpp) % MOD * invN % MOD;

        int goodNonzero = goodTotal - (zeroGood ? 1 : 0);
        long long answer = (e_k * (zeroGood ? 1 : 0) + o_k * goodNonzero) % MOD;

        return (int)((answer % MOD + MOD) % MOD);
    }
};
