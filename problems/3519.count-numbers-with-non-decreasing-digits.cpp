// @leetcode id=3519 questionId=3810 slug=count-numbers-with-non-decreasing-digits lang=cpp site=leetcode.com title="Count Numbers with Non-Decreasing Digits "
class Solution {
public:
    static const long long MOD = 1000000007;
    long long fact[500], inv_fact[500];

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

    void initFact() {
        fact[0] = 1;
        for (int i = 1; i < 500; i++) fact[i] = fact[i - 1] * i % MOD;
        inv_fact[499] = modpow(fact[499], MOD - 2, MOD);
        for (int i = 499; i > 0; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n || n < 0) return 0;
        return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
    }

    // decimal string minus 1
    string decSubOne(string dec) {
        int n = dec.size();
        int i = n - 1;
        while (i >= 0 && dec[i] == '0') {
            dec[i] = '9';
            i--;
        }
        dec[i]--;
        int start = 0;
        while (start < n - 1 && dec[start] == '0') start++;
        return dec.substr(start);
    }

    // convert decimal string to base b digits (most significant first)
    vector<int> decToBaseB(string dec, int b) {
        if (dec == "0") return {0};
        vector<int> result;
        while (dec != "0") {
            string quotient;
            int rem = 0;
            for (char c : dec) {
                int cur = rem * 10 + (c - '0');
                quotient.push_back('0' + cur / b);
                rem = cur % b;
            }
            result.push_back(rem);
            int start = 0;
            while (start < (int)quotient.size() - 1 && quotient[start] == '0') start++;
            dec = quotient.substr(start);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // count of length-L (exact) base-b numbers with non-decreasing digits, no leading zero, <= N (digits array)
    long long tightCount(vector<int>& N, int b) {
        int L = N.size();
        // dp[last][tight] memo via recursion with position
        vector<vector<vector<long long>>> memo(L, vector<vector<long long>>(b + 1, vector<long long>(2, -1)));

        function<long long(int, int, bool)> rec = [&](int pos, int last, bool tight) -> long long {
            if (pos == L) return 1;
            if (memo[pos][last][tight] != -1) return memo[pos][last][tight];

            int lo = (pos == 0) ? 1 : last;
            int hi = tight ? N[pos] : (b - 1);

            long long total = 0;
            for (int d = lo; d <= hi; d++) {
                bool newTight = tight && (d == N[pos]);
                total = (total + rec(pos + 1, d, newTight)) % MOD;
            }

            memo[pos][last][tight] = total;
            return total;
        };

        return rec(0, 0, true);
    }

    long long countUpTo(string dec, int b) {
        if (dec == "0") return 1;
        vector<int> digits = decToBaseB(dec, b);
        int L = digits.size();

        long long total = 1; // x = 0
        for (int len = 1; len < L; len++) {
            total = (total + nCr(len + b - 2, len)) % MOD;
        }
        total = (total + tightCount(digits, b)) % MOD;
        return total;
    }

    int countNumbers(string l, string r, int b) {
        initFact();
        long long countR = countUpTo(r, b);
        string lMinusOne = decSubOne(l);
        long long countLMinus1 = countUpTo(lMinusOne, b);
        long long ans = (countR - countLMinus1 + MOD) % MOD;
        return (int)ans;
    }
};
