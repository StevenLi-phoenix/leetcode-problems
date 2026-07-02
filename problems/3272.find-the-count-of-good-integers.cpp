// @leetcode id=3272 questionId=3548 slug=find-the-count-of-good-integers lang=cpp site=leetcode.com title="Find the Count of Good Integers"
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        int half = (n + 1) / 2;
        long long fact[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
        unordered_set<long long> seen;
        long long ans = 0;

        vector<int> digits(half);
        function<void(int)> gen = [&](int idx) {
            if (idx == half) {
                vector<int> s(n);
                for (int i = 0; i < half; ++i) s[i] = digits[i];
                for (int i = half; i < n; ++i) s[i] = digits[n - 1 - i];

                long long val = 0;
                for (int d : s) val = (val * 10 + d) % k;
                if (val != 0) return;

                int counts[10] = {0};
                for (int d : s) counts[d]++;
                long long key = 0;
                for (int i = 0; i < 10; ++i) key = key * 11 + counts[i];
                if (seen.count(key)) return;
                seen.insert(key);

                long long denom = 1;
                for (int i = 0; i < 10; ++i) denom *= fact[counts[i]];
                long long total = fact[n] / denom;

                long long leadZero = 0;
                if (counts[0] > 0) {
                    counts[0]--;
                    long long denom2 = 1;
                    for (int i = 0; i < 10; ++i) denom2 *= fact[counts[i]];
                    leadZero = fact[n - 1] / denom2;
                }
                ans += total - leadZero;
                return;
            }
            int lo = (idx == 0) ? 1 : 0;
            for (int d = lo; d <= 9; ++d) {
                digits[idx] = d;
                gen(idx + 1);
            }
        };
        gen(0);
        return ans;
    }
};
