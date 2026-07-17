// @leetcode id=1723 questionId=1825 slug=find-minimum-time-to-finish-all-jobs lang=cpp site=leetcode.com title="Find Minimum Time to Finish All Jobs"
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        int full = 1 << n;
        vector<int> sum(full, 0);
        for (int mask = 1; mask < full; mask++) {
            int lb = mask & (-mask);
            int idx = __builtin_ctz(lb);
            sum[mask] = sum[mask ^ lb] + jobs[idx];
        }

        vector<int> dp(sum.begin(), sum.end());

        for (int worker = 2; worker <= k; worker++) {
            vector<int> ndp(full, INT_MAX);
            ndp[0] = 0;
            for (int mask = 1; mask < full; mask++) {
                for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                    int cand = max(dp[mask ^ sub], sum[sub]);
                    ndp[mask] = min(ndp[mask], cand);
                }
            }
            dp = ndp;
        }

        return dp[full - 1];
    }
};
