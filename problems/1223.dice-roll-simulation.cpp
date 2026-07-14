// @leetcode id=1223 questionId=1343 slug=dice-roll-simulation lang=cpp site=leetcode.com title="Dice Roll Simulation"
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        const long long MOD = 1e9 + 7;
        // dp[face][streak] = ways to reach current roll ending with `face`
        // repeated `streak` times consecutively.
        vector<vector<long long>> dp(6, vector<long long>(16, 0));
        for (int f = 0; f < 6; f++) dp[f][1] = 1;

        for (int roll = 2; roll <= n; roll++) {
            vector<vector<long long>> ndp(6, vector<long long>(16, 0));
            for (int f = 0; f < 6; f++) {
                long long totalOthers = 0;
                for (int g = 0; g < 6; g++) {
                    if (g == f) continue;
                    for (int s = 1; s <= rollMax[g]; s++) totalOthers = (totalOthers + dp[g][s]) % MOD;
                }
                for (int s = 2; s <= rollMax[f]; s++) {
                    ndp[f][s] = dp[f][s - 1];
                }
                ndp[f][1] = totalOthers;
            }
            dp = ndp;
        }

        long long total = 0;
        for (int f = 0; f < 6; f++) {
            for (int s = 1; s <= rollMax[f]; s++) total = (total + dp[f][s]) % MOD;
        }
        return (int)total;
    }
};
