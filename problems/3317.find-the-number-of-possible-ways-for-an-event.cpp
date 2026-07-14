// @leetcode id=3317 questionId=3604 slug=find-the-number-of-possible-ways-for-an-event lang=cpp site=leetcode.com title="Find the Number of Possible Ways for an Event"
class Solution {
public:
    int numberOfWays(int n, int x, int y) {
        const long long MOD = 1e9 + 7;
        int kMax = min(n, x);

        // Stirling numbers of the second kind: S(i,k) = k*S(i-1,k) + S(i-1,k-1).
        vector<vector<long long>> S(n + 1, vector<long long>(kMax + 1, 0));
        S[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= min(i, kMax); k++) {
                S[i][k] = (k * S[i - 1][k] + S[i - 1][k - 1]) % MOD;
            }
        }

        // C(x,k) via Pascal's triangle.
        vector<vector<long long>> C(x + 1, vector<long long>(kMax + 1, 0));
        for (int i = 0; i <= x; i++) {
            C[i][0] = 1;
            for (int k = 1; k <= min(i, kMax); k++) {
                C[i][k] = (C[i - 1][k] + (k > 0 ? C[i - 1][k - 1] : 0)) % MOD;
            }
        }

        vector<long long> fact(kMax + 1);
        fact[0] = 1;
        for (int k = 1; k <= kMax; k++) fact[k] = fact[k - 1] * k % MOD;

        long long ans = 0;
        long long yPow = 1;
        for (int k = 0; k <= kMax; k++) {
            if (k > 0) yPow = yPow * y % MOD;
            if (k == 0) continue;
            long long term = S[n][k] * C[x][k] % MOD * fact[k] % MOD * yPow % MOD;
            ans = (ans + term) % MOD;
        }
        return (int)ans;
    }
};
