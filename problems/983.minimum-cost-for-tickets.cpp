// @leetcode id=983 questionId=1025 slug=minimum-cost-for-tickets lang=cpp site=leetcode.com title="Minimum Cost For Tickets"
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days.back();
        vector<int> dp(lastDay + 1, 0);
        unordered_set<int> travelDays(days.begin(), days.end());

        for (int d = 1; d <= lastDay; d++) {
            if (!travelDays.count(d)) {
                dp[d] = dp[d - 1];
                continue;
            }
            int cost1 = dp[d - 1] + costs[0];
            int cost7 = dp[max(0, d - 7)] + costs[1];
            int cost30 = dp[max(0, d - 30)] + costs[2];
            dp[d] = min({cost1, cost7, cost30});
        }
        return dp[lastDay];
    }
};
