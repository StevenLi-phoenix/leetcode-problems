// @leetcode id=3395 questionId=3700 slug=subsequences-with-a-unique-middle-mode-i lang=cpp site=leetcode.com title="Subsequences with a Unique Middle Mode I"
class Solution {
public:
    static const long long MOD = 1000000007;
    long long fact[1005], inv_fact[1005];

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

    void initFact(int n) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        inv_fact[n] = modpow(fact[n], MOD - 2, MOD);
        for (int i = n; i > 0; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;
    }

    long long nCr(long long n, long long r) {
        if (r < 0 || n < 0 || r > n) return 0;
        return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
    }

    int subsequencesWithMiddleMode(vector<int>& nums) {
        int n = nums.size();
        initFact(1000);

        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();

        vector<int> comp(n);
        for (int i = 0; i < n; i++) {
            comp[i] = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
        }

        vector<int> leftCount(m, 0), rightCount(m, 0);
        for (int i = 1; i < n; i++) rightCount[comp[i]]++;

        long long ans = 0;

        for (int p = 0; p < n; p++) {
            int v = comp[p];
            int L = p, R = n - 1 - p;

            if (L >= 2 && R >= 2) {
                long long cntLeftV = leftCount[v], cntRightV = rightCount[v];
                long long leftNonV = L - cntLeftV;
                long long rightNonV = R - cntRightV;

                long long term = nCr(cntLeftV, 2) * nCr(cntRightV, 2) % MOD;

                term = (term + nCr(cntLeftV, 1) * nCr(leftNonV, 1) % MOD * nCr(cntRightV, 2) % MOD) % MOD;
                term = (term + nCr(cntLeftV, 2) * nCr(cntRightV, 1) % MOD * nCr(rightNonV, 1) % MOD) % MOD;

                for (int a = 0; a <= 2; a++) {
                    int b = 2 - a;
                    long long ways = nCr(cntLeftV, a) * nCr(leftNonV, 2 - a) % MOD * nCr(cntRightV, b) % MOD * nCr(rightNonV, 2 - b) % MOD;
                    term = (term + ways) % MOD;
                }

                // k = 2 case, excluding value v from both frequency arrays
                long long sumRightC2 = 0, sumLeftC2 = 0;
                long long crossSumForLeft1 = 0; // sum over w!=v: left[w]*right[w]*(rightNonV-right[w])
                long long crossSumForRight1 = 0; // sum over w!=v: right[w]*left[w]*(leftNonV-left[w])

                for (int w = 0; w < m; w++) {
                    if (w == v) continue;
                    long long lc = leftCount[w], rc = rightCount[w];
                    if (rc >= 2) sumRightC2 = (sumRightC2 + nCr(rc, 2)) % MOD;
                    if (lc >= 2) sumLeftC2 = (sumLeftC2 + nCr(lc, 2)) % MOD;
                    if (lc > 0 && rc > 0) {
                        crossSumForLeft1 = (crossSumForLeft1 + lc * rc % MOD * ((rightNonV - rc) % MOD + MOD) % MOD) % MOD;
                        crossSumForRight1 = (crossSumForRight1 + rc * lc % MOD * ((leftNonV - lc) % MOD + MOD) % MOD) % MOD;
                    }
                }

                long long totalDistinctPairsB = (nCr(rightNonV, 2) - sumRightC2 + MOD) % MOD;
                long long waysNonV1 = (leftNonV % MOD * totalDistinctPairsB % MOD - crossSumForLeft1 % MOD + MOD) % MOD;
                long long vChoice1 = nCr(cntLeftV, 1) * nCr(cntRightV, 0) % MOD;
                term = (term + vChoice1 * waysNonV1) % MOD;

                long long totalDistinctPairsA = (nCr(leftNonV, 2) - sumLeftC2 + MOD) % MOD;
                long long waysNonV2 = (rightNonV % MOD * totalDistinctPairsA % MOD - crossSumForRight1 % MOD + MOD) % MOD;
                long long vChoice2 = nCr(cntLeftV, 0) * nCr(cntRightV, 1) % MOD;
                term = (term + vChoice2 * waysNonV2) % MOD;

                ans = (ans + term) % MOD;
            }

            leftCount[v]++;
            if (p + 1 < n) rightCount[comp[p + 1]]--;
        }

        return (int)ans;
    }
};
