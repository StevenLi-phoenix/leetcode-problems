// @leetcode id=188 questionId=188 slug=best-time-to-buy-and-sell-stock-iv lang=cpp site=leetcode.com title="Best Time to Buy and Sell Stock IV"
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);

        for (int price : prices) {
            for (int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j - 1] - price);
                sell[j] = max(sell[j], buy[j] + price);
            }
        }

        return sell[k];
    }
};
