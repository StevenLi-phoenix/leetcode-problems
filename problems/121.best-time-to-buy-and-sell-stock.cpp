// @leetcode id=121 questionId=121 slug=best-time-to-buy-and-sell-stock lang=cpp site=leetcode.com title="Best Time to Buy and Sell Stock"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
