// @leetcode id=3971 questionId=4274 slug=maximum-total-value lang=cpp site=leetcode.com title="Maximum Total Value"
class Solution {
public:
    static const long long MOD = 1000000007;

    long long countAtLeast(vector<int>& value, vector<int>& decay, long long X) {
        long long total = 0;
        int n = value.size();
        for (int i = 0; i < n; i++) {
            if (value[i] < X) continue;
            long long ni = (value[i] - X) / decay[i] + 1;
            total += ni;
        }
        return total;
    }

    long long sumAtLeast(vector<int>& value, vector<int>& decay, long long X) {
        long long total = 0;
        int n = value.size();
        for (int i = 0; i < n; i++) {
            if (value[i] < X) continue;
            long long ni = (value[i] - X) / decay[i] + 1;
            long long half = ni * (ni - 1) / 2; // exact, fits int64
            long long term1 = (ni % MOD) * (value[i] % MOD) % MOD;
            long long term2 = (half % MOD) * (decay[i] % MOD) % MOD;
            long long contrib = (term1 - term2 % MOD + MOD) % MOD;
            total = (total + contrib) % MOD;
        }
        return total;
    }

    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        long long maxVal = 0;
        for (int v : value) maxVal = max(maxVal, (long long)v);

        long long totalNonNeg = countAtLeast(value, decay, 0);
        if (totalNonNeg <= m) {
            return (int)sumAtLeast(value, decay, 0);
        }

        long long lo = 0, hi = maxVal, X = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (countAtLeast(value, decay, mid) >= (long long)m) {
                X = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        long long countHigh = countAtLeast(value, decay, X + 1);
        long long sumHigh = sumAtLeast(value, decay, X + 1);
        long long remaining = m - countHigh;

        long long ans = (sumHigh + (remaining % MOD) * (X % MOD) % MOD) % MOD;
        return (int)ans;
    }
};
