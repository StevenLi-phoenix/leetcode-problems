// @leetcode id=3343 questionId=3637 slug=count-number-of-balanced-permutations lang=cpp site=leetcode.com title="Count Number of Balanced Permutations"
class Solution {
public:
    int countBalancedPermutations(string num) {
        const long long MOD = 1e9 + 7;
        int n = num.size();

        int cnt[10] = {0};
        int totalSum = 0;
        for (char c : num) {
            ++cnt[c - '0'];
            totalSum += c - '0';
        }

        int evenCount = (n + 1) / 2;
        int oddCount = n / 2;
        if (totalSum % 2 != 0) return 0;
        int half = totalSum / 2;

        vector<long long> fact(n + 1), invFact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
        invFact[n] = modpow(fact[n], MOD - 2, MOD);
        for (int i = n; i > 0; --i) invFact[i - 1] = invFact[i] * i % MOD;

        auto C = [&](int a, int b) -> long long {
            if (b < 0 || b > a) return 0;
            return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
        };

        vector<vector<long long>> dp(evenCount + 1, vector<long long>(half + 1, 0));
        dp[0][0] = 1;

        for (int d = 0; d <= 9; ++d) {
            int c = cnt[d];
            if (c == 0) continue;

            vector<vector<long long>> ndp(evenCount + 1, vector<long long>(half + 1, 0));
            for (int j = 0; j <= evenCount; ++j) {
                for (int s = 0; s <= half; ++s) {
                    if (dp[j][s] == 0) continue;
                    for (int k = 0; k <= min(c, evenCount - j); ++k) {
                        int ns = s + k * d;
                        if (ns > half) break;
                        ndp[j + k][ns] = (ndp[j + k][ns] + dp[j][s] * C(c, k)) % MOD;
                    }
                }
            }
            dp = ndp;
        }

        long long ways = dp[evenCount][half];
        long long ans = ways * fact[evenCount] % MOD * fact[oddCount] % MOD;
        for (int d = 0; d <= 9; ++d) {
            ans = ans * invFact[cnt[d]] % MOD;
        }
        return (int)ans;
    }

private:
    long long modpow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }
};
