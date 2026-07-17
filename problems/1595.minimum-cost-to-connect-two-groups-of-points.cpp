// @leetcode id=1595 questionId=1717 slug=minimum-cost-to-connect-two-groups-of-points lang=cpp site=leetcode.com title="Minimum Cost to Connect Two Groups of Points"
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int size1 = cost.size();
        int size2 = cost[0].size();
        int fullMask = 1 << size2;
        const int INF = INT_MAX / 2;

        vector<vector<int>> dp(size1 + 1, vector<int>(fullMask, INF));
        dp[0][0] = 0;

        for (int i = 0; i < size1; i++) {
            vector<int>& next = dp[i + 1];

            for (int mask = 0; mask < fullMask; mask++) {
                if (dp[i][mask] >= INF) continue;
                for (int j = 0; j < size2; j++) {
                    int nm = mask | (1 << j);
                    next[nm] = min(next[nm], dp[i][mask] + cost[i][j]);
                }
            }

            for (int mask = 0; mask < fullMask; mask++) {
                if (next[mask] >= INF) continue;
                for (int j = 0; j < size2; j++) {
                    int nm = mask | (1 << j);
                    if (nm != mask) next[nm] = min(next[nm], next[mask] + cost[i][j]);
                }
            }
        }

        return dp[size1][fullMask - 1];
    }
};
