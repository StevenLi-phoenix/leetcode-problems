// @leetcode id=309 questionId=309 slug=best-time-to-buy-and-sell-stock-with-cooldown lang=cpp site=leetcode.com title="Best Time to Buy and Sell Stock with Cooldown"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int hold = -prices[0];
        int sold = 0;
        int rest = 0;

        for (int i = 1; i < n; i++) {
            int prevHold = hold, prevSold = sold, prevRest = rest;
            hold = max(prevHold, prevRest - prices[i]);
            sold = prevHold + prices[i];
            rest = max(prevRest, prevSold);
        }

        return max(sold, rest);
    }
};
