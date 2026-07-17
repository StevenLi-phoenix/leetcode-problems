// @leetcode id=879 questionId=911 slug=profitable-schemes lang=cpp site=leetcode.com title="Profitable Schemes"
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const long long MOD = 1000000007;
        int m = group.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(minProfit + 1, 0));
        for (int members = 0; members <= n; members++) dp[members][0] = 1;

        for (int i = 0; i < m; i++) {
            int g = group[i], p = profit[i];
            for (int members = n; members >= g; members--) {
                for (int prof = minProfit; prof >= 0; prof--) {
                    int prevProf = max(0, prof - p);
                    dp[members][prof] = (dp[members][prof] + dp[members - g][prevProf]) % MOD;
                }
            }
        }

        return (int)dp[n][minProfit];
    }
};
