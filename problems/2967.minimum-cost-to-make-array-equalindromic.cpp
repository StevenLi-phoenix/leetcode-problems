// @leetcode id=2967 questionId=3229 slug=minimum-cost-to-make-array-equalindromic lang=cpp site=leetcode.com title="Minimum Cost to Make Array Equalindromic"
class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        static const vector<long long> palindromes = buildPalindromes();

        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = sorted.size();
        long long loMed = sorted[(n - 1) / 2];
        long long hiMed = sorted[n / 2];

        auto cost = [&](long long y) {
            long long total = 0;
            for (int x : nums) total += llabs((long long)x - y);
            return total;
        };

        vector<long long> candidates;
        auto addCandidates = [&](long long target) {
            int idx = lower_bound(palindromes.begin(), palindromes.end(), target) - palindromes.begin();
            if (idx < (int)palindromes.size()) candidates.push_back(palindromes[idx]);
            if (idx > 0) candidates.push_back(palindromes[idx - 1]);
        };
        addCandidates(loMed);
        addCandidates(hiMed);

        long long best = LLONG_MAX;
        for (long long c : candidates) best = min(best, cost(c));
        return best;
    }

private:
    static long long revDigits(long long x) {
        long long r = 0;
        while (x > 0) { r = r * 10 + x % 10; x /= 10; }
        return r;
    }

    static vector<long long> buildPalindromes() {
        vector<long long> result;
        for (int len = 1; len <= 9; len++) {
            int halfLen = (len + 1) / 2;
            long long lo = 1;
            for (int i = 1; i < halfLen; i++) lo *= 10;
            long long hi = lo * 10 - 1;
            long long pow10half = lo * 10;
            for (long long h = lo; h <= hi; h++) {
                long long full;
                if (len % 2 == 0) {
                    full = h * pow10half + revDigits(h);
                } else {
                    long long reducedPow = pow10half / 10;
                    full = h * reducedPow + revDigits(h / 10);
                }
                result.push_back(full);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
