// @leetcode id=483 questionId=483 slug=smallest-good-base lang=cpp site=leetcode.com title="Smallest Good Base"
class Solution {
public:
    string smallestGoodBase(string n) {
        // n = 1 + k + k^2 + ... + k^(m-1). More digits (larger m) means a
        // smaller required base, so try the longest possible digit count
        // first; estimate k via the m-1-th root of n and check the
        // neighborhood exactly. m=2 (k=n-1) always works as a fallback.
        long long N = stoll(n);

        // exact sum, computed with __int128; caller only needs to know
        // whether it's <, ==, or > N, so no overflow-truncating shortcuts.
        auto sumWithBase = [](__int128 k, int m) -> __int128 {
            __int128 sum = 0, term = 1;
            for (int i = 0; i < m; i++) {
                sum += term;
                term *= k;
            }
            return sum;
        };

        for (int m = 60; m >= 2; m--) {
            double approx = pow((double)N, 1.0 / (m - 1));
            long long k = (long long)approx;
            for (long long cand = max(2LL, k - 2); cand <= k + 2; cand++) {
                if (sumWithBase(cand, m) == (__int128)N) return to_string(cand);
            }
        }
        return to_string(N - 1);
    }
};
