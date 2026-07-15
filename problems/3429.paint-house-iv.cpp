// @leetcode id=3429 questionId=3737 slug=paint-house-iv lang=cpp site=leetcode.com title="Paint House IV"
class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        const long long INF = LLONG_MAX / 2;
        vector<vector<long long>> dp(3, vector<long long>(3, INF));

        for (int l = 0; l < 3; l++) {
            for (int r = 0; r < 3; r++) {
                if (l == r) continue;
                dp[l][r] = cost[0][l] + cost[n - 1][r];
            }
        }

        for (int i = 1; i < n / 2; i++) {
            vector<vector<long long>> ndp(3, vector<long long>(3, INF));
            for (int l = 0; l < 3; l++) {
                for (int r = 0; r < 3; r++) {
                    if (l == r || dp[l][r] >= INF) continue;
                    for (int nl = 0; nl < 3; nl++) {
                        if (nl == l) continue;
                        for (int nr = 0; nr < 3; nr++) {
                            if (nr == r || nr == nl) continue;
                            long long candidate = dp[l][r] + cost[i][nl] + cost[n - 1 - i][nr];
                            ndp[nl][nr] = min(ndp[nl][nr], candidate);
                        }
                    }
                }
            }
            dp = ndp;
        }

        long long best = INF;
        for (int l = 0; l < 3; l++)
            for (int r = 0; r < 3; r++)
                best = min(best, dp[l][r]);
        return best;
    }
};
