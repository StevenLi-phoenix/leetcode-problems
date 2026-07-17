// @leetcode id=2830 questionId=2979 slug=maximize-the-profit-as-the-salesman lang=cpp site=leetcode.com title="Maximize the Profit as the Salesman"
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<vector<pair<int, int>>> byEnd(n);
        for (auto& o : offers) {
            byEnd[o[1]].push_back({o[0], o[2]});
        }

        vector<int> dp(n + 1, 0);
        for (int house = 0; house < n; house++) {
            dp[house + 1] = dp[house];
            for (auto& [start, gold] : byEnd[house]) {
                dp[house + 1] = max(dp[house + 1], dp[start] + gold);
            }
        }
        return dp[n];
    }
};
