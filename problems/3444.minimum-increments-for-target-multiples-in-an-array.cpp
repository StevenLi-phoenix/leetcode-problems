// @leetcode id=3444 questionId=3697 slug=minimum-increments-for-target-multiples-in-an-array lang=cpp site=leetcode.com title="Minimum Increments for Target Multiples in an Array"
class Solution {
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        int k = target.size();
        int full = 1 << k;
        vector<long long> lcmOf(full, 0);
        for (int mask = 1; mask < full; mask++) {
            long long l = 1;
            for (int b = 0; b < k; b++) {
                if (mask & (1 << b)) {
                    long long g = gcd(l, (long long)target[b]);
                    l = l / g * target[b];
                }
            }
            lcmOf[mask] = l;
        }

        const long long INF = LLONG_MAX / 2;
        vector<long long> dp(full, INF);
        dp[0] = 0;

        for (int num : nums) {
            vector<long long> costForSub(full, 0);
            for (int sub = 1; sub < full; sub++) {
                long long L = lcmOf[sub];
                long long nextMultiple = ((num + L - 1) / L) * L;
                costForSub[sub] = nextMultiple - num;
            }

            vector<long long> newDp = dp;
            for (int mask = 0; mask < full; mask++) {
                if (dp[mask] >= INF) continue;
                for (int sub = 1; sub < full; sub++) {
                    int nmask = mask | sub;
                    long long cand = dp[mask] + costForSub[sub];
                    if (cand < newDp[nmask]) newDp[nmask] = cand;
                }
            }
            dp = newDp;
        }

        return (int)dp[full - 1];
    }
};
