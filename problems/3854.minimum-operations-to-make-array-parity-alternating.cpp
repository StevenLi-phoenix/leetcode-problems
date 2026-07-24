// @leetcode id=3854 questionId=4219 slug=minimum-operations-to-make-array-parity-alternating lang=cpp site=leetcode.com title="Minimum Operations to Make Array Parity Alternating"
class Solution {
public:
    pair<long long, long long> solveForPattern(vector<int>& nums, int p) {
        int n = nums.size();
        vector<long long> fixedVals, freeVals;
        long long ops = 0;
        for (int i = 0; i < n; i++) {
            int reqParity = (p + i) % 2;
            int actualParity = ((nums[i] % 2) + 2) % 2;
            if (actualParity == reqParity) fixedVals.push_back(nums[i]);
            else { freeVals.push_back(nums[i]); ops++; }
        }

        bool hasFixed = !fixedVals.empty();
        long long fixedMin = LLONG_MAX, fixedMax = LLONG_MIN;
        for (long long v : fixedVals) { fixedMin = min(fixedMin, v); fixedMax = max(fixedMax, v); }

        auto checkR = [&](long long R) -> bool {
            vector<long long> candidates;
            if (hasFixed) {
                candidates.push_back(fixedMax - R);
                candidates.push_back(fixedMin);
            }
            for (long long v : freeVals) {
                candidates.push_back(v - 1 - R);
                candidates.push_back(v - 1);
                candidates.push_back(v + 1 - R);
                candidates.push_back(v + 1);
            }
            for (long long L : candidates) {
                bool ok = true;
                if (hasFixed && !(L <= fixedMin && L + R >= fixedMax)) ok = false;
                if (ok) {
                    for (long long v : freeVals) {
                        bool a = (L <= v - 1 && v - 1 <= L + R);
                        bool b = (L <= v + 1 && v + 1 <= L + R);
                        if (!a && !b) { ok = false; break; }
                    }
                }
                if (ok) return true;
            }
            return false;
        };

        long long bestR;
        if (checkR(0)) bestR = 0;
        else if (checkR(1)) bestR = 1;
        else {
            auto feasibleMerged = [&](long long R) -> bool {
                long long lo = LLONG_MIN, hi = LLONG_MAX;
                if (hasFixed) {
                    lo = max(lo, fixedMax - R);
                    hi = min(hi, fixedMin);
                }
                for (long long v : freeVals) {
                    lo = max(lo, v - 1 - R);
                    hi = min(hi, v + 1);
                }
                return lo <= hi;
            };
            long long lo = 2, hi = 4200000000LL;
            while (lo < hi) {
                long long mid = lo + (hi - lo) / 2;
                if (feasibleMerged(mid)) hi = mid; else lo = mid + 1;
            }
            bestR = lo;
        }

        return {ops, bestR};
    }

    vector<int> makeParityAlternating(vector<int>& nums) {
        auto [ops0, range0] = solveForPattern(nums, 0);
        auto [ops1, range1] = solveForPattern(nums, 1);
        long long minOps = min(ops0, ops1);
        long long best = LLONG_MAX;
        if (ops0 == minOps) best = min(best, range0);
        if (ops1 == minOps) best = min(best, range1);
        return {(int)minOps, (int)best};
    }
};
