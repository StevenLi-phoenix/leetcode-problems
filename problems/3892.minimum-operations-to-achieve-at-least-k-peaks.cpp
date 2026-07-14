// @leetcode id=3892 questionId=4263 slug=minimum-operations-to-achieve-at-least-k-peaks lang=cpp site=leetcode.com title="Minimum Operations to Achieve At Least K Peaks"
class Solution {
public:
    static constexpr long long INF = LLONG_MAX / 2;

    // Min cost to choose exactly `want` non-adjacent entries from c, minimizing sum.
    long long solveLinear(const vector<long long>& c, int want) {
        int m = c.size();
        if (want == 0) return 0;
        if (want > (m + 1) / 2) return INF;
        vector<vector<long long>> dp(m + 1, vector<long long>(want + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= want; j++) {
                long long best = dp[i - 1][j];
                if (j > 0) {
                    long long prev = (i >= 2) ? dp[i - 2][j - 1] : (j - 1 == 0 ? 0 : INF);
                    if (prev < INF) best = min(best, prev + c[i - 1]);
                }
                dp[i][j] = best;
            }
        }
        return dp[m][want];
    }

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return 0;
        if (k > n / 2) return -1;

        vector<long long> cost(n);
        for (int i = 0; i < n; i++) {
            int prevIdx = (i - 1 + n) % n, nextIdx = (i + 1) % n;
            long long neigh = max(nums[prevIdx], nums[nextIdx]);
            cost[i] = max(0LL, neigh + 1 - nums[i]);
        }

        // Case A: index 0 is not a peak.
        vector<long long> costsA(cost.begin() + 1, cost.end());
        long long resA = solveLinear(costsA, k);

        // Case B: index 0 is a peak, so indices 1 and n-1 can't be.
        long long resB = INF;
        if (n >= 2) {
            vector<long long> costsB;
            if (n >= 4) costsB.assign(cost.begin() + 2, cost.end() - 1);
            long long sub = solveLinear(costsB, k - 1);
            if (sub < INF) resB = cost[0] + sub;
        }

        long long ans = min(resA, resB);
        return ans >= INF ? -1 : (int)ans;
    }
};
