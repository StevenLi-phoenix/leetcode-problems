// @leetcode id=122 questionId=122 slug=best-time-to-buy-and-sell-stock-ii lang=cpp site=leetcode.com title="Best Time to Buy and Sell Stock II"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};
