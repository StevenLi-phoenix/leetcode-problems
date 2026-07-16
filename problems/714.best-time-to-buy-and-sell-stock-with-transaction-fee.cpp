// @leetcode id=714 questionId=714 slug=best-time-to-buy-and-sell-stock-with-transaction-fee lang=cpp site=leetcode.com title="Best Time to Buy and Sell Stock with Transaction Fee"
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        long long cash = 0, hold = LLONG_MIN / 2;
        for (int p : prices) {
            long long newCash = max(cash, hold + p - fee);
            long long newHold = max(hold, cash - p);
            cash = newCash;
            hold = newHold;
        }
        return (int)cash;
    }
};
