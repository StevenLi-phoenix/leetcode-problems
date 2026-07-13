// @leetcode id=3725 questionId=4069 slug=count-ways-to-choose-coprime-integers-from-rows lang=cpp site=leetcode.com title="Count Ways to Choose Coprime Integers from Rows"
class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        // Mobius inversion: the number of selections with gcd exactly 1
        // equals sum_d mu(d) * (number of selections where every chosen
        // value is divisible by d), since values are bounded by 150 only
        // divisors up to 150 matter.
        const int MOD = 1e9 + 7;
        const int MAXV = 150;

        vector<int> mu(MAXV + 1, 0);
        vector<int> primes;
        vector<bool> isComposite(MAXV + 1, false);
        mu[1] = 1;
        for (int i = 2; i <= MAXV; i++) {
            if (!isComposite[i]) {
                primes.push_back(i);
                mu[i] = -1;
            }
            for (int p : primes) {
                if ((long long)i * p > MAXV) break;
                isComposite[i * p] = true;
                if (i % p == 0) {
                    mu[i * p] = 0;
                    break;
                } else {
                    mu[i * p] = -mu[i];
                }
            }
        }

        int m = mat.size();
        vector<vector<int>> countDiv(m, vector<int>(MAXV + 1, 0));
        for (int r = 0; r < m; r++) {
            for (int v : mat[r]) {
                for (int d = 1; d <= v && d <= MAXV; d++) {
                    if (v % d == 0) countDiv[r][d]++;
                }
            }
        }

        long long ans = 0;
        for (int d = 1; d <= MAXV; d++) {
            if (mu[d] == 0) continue;
            long long prod = 1;
            for (int r = 0; r < m; r++) {
                prod = (prod * countDiv[r][d]) % MOD;
                if (prod == 0) break;
            }
            ans = (ans + (long long)mu[d] * prod % MOD + MOD) % MOD;
        }
        return (int)ans;
    }
};
