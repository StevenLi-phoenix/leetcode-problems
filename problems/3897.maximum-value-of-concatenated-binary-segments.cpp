// @leetcode id=3897 questionId=4278 slug=maximum-value-of-concatenated-binary-segments lang=cpp site=leetcode.com title="Maximum Value of Concatenated Binary Segments"
class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        const long long MOD = 1'000'000'007;
        int n = nums1.size();
        vector<pair<int, int>> segs(n); // (ones, zeros)
        for (int i = 0; i < n; i++) segs[i] = {nums1[i], nums0[i]};

        // A should precede B iff value(A+B) > value(B+A). Writing
        // value(X) = 2^lenX - 2^zX, the sign of
        // D = value(A)*(2^lenB-1) - value(B)*(2^lenA-1) decides it, and D
        // expands (the 2^(lenA+lenB) terms cancel) to exactly six signed
        // power-of-two terms:
        //   -2^lenA - 2^(za+lenB) + 2^za + 2^lenB + 2^(zb+lenA) - 2^zb
        // Exponents run up to ~4*10^4, far beyond any floating type's safe
        // precision/range for this comparison (verified: both a naive log
        // subtraction and a log1p-based reformulation gave wrong answers on
        // adversarial cases), so resolve the sign exactly: merge same-
        // exponent terms, then repeatedly fold the two largest exponents
        // together while they're within a few bits of each other (so the
        // combined coefficient stays a small integer) until one term
        // provably dominates the rest (its exponent lead exceeds the
        // maximum possible combined magnitude of everything smaller).
        auto aFirst = [&](const pair<int,int>& A, const pair<int,int>& B) {
            long long oa = A.first, za = A.second, ob = B.first, zb = B.second;
            long long lenA = oa + za, lenB = ob + zb;

            // Fixed-size stack array instead of a heap-allocated map: this
            // comparator runs ~n*log(n) times, and per-call heap allocation
            // (an earlier std::map version) was the TLE culprit, not the math.
            long long exp[6] = {lenA, za + lenB, za, lenB, zb + lenA, zb};
            long long coeff[6] = {-1, -1, 1, 1, 1, -1};
            int m = 6;
            // Merge duplicate exponents in place (m <= 6, so O(m^2) is trivial).
            for (int i = 0; i < m; i++)
                for (int j = i + 1; j < m; j++)
                    if (exp[j] == exp[i]) {
                        coeff[i] += coeff[j];
                        exp[j] = exp[--m]; coeff[j] = coeff[m];
                        j--;
                    }
            // Drop zero-coefficient entries.
            for (int i = 0; i < m; i++)
                if (coeff[i] == 0) { exp[i] = exp[--m]; coeff[i] = coeff[m]; i--; }
            if (m == 0) return false; // D == 0, order irrelevant

            // Selection sort descending by exponent (m <= 6).
            for (int i = 0; i < m; i++) {
                int best = i;
                for (int j = i + 1; j < m; j++) if (exp[j] > exp[best]) best = j;
                swap(exp[i], exp[best]); swap(coeff[i], coeff[best]);
            }

            while (m > 1) {
                long long gap = exp[0] - exp[1];
                if (gap >= 4) break; // 2^4=16 safely exceeds any possible combined remaining magnitude (<=6)
                coeff[1] = coeff[0] * (1LL << gap) + coeff[1];
                // shift everything down by one slot
                for (int i = 0; i < m - 1; i++) { exp[i] = exp[i + 1]; coeff[i] = coeff[i + 1]; }
                m--;
                if (coeff[0] == 0) {
                    for (int i = 0; i < m - 1; i++) { exp[i] = exp[i + 1]; coeff[i] = coeff[i + 1]; }
                    m--;
                }
                if (m == 0) return false; // D == 0, order irrelevant
            }
            return coeff[0] > 0;
        };
        sort(segs.begin(), segs.end(), aFirst);

        int maxLen = 0;
        for (auto& [o, z] : segs) maxLen = max(maxLen, o + z);
        vector<long long> pow2(maxLen + 1);
        pow2[0] = 1;
        for (int i = 1; i <= maxLen; i++) pow2[i] = pow2[i - 1] * 2 % MOD;

        long long val = 0;
        for (auto& [o, z] : segs) {
            long long segVal = (pow2[o] - 1 + MOD) % MOD * pow2[z] % MOD;
            val = (val * pow2[o + z] + segVal) % MOD;
        }
        return (int)val;
    }
};
