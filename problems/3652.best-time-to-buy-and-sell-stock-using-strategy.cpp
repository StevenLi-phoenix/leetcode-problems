// @leetcode id=3652 questionId=3980 slug=best-time-to-buy-and-sell-stock-using-strategy lang=cpp site=leetcode.com title="Best Time to Buy and Sell Stock using Strategy"
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = (int)prices.size();
        int h = k / 2;

        vector<long long> prefP(n + 1, 0);   // prefix of prices
        vector<long long> prefSP(n + 1, 0);  // prefix of strategy[i] * prices[i]

        for (int i = 0; i < n; i++) {
            prefP[i + 1] = prefP[i] + (long long)prices[i];
            prefSP[i + 1] = prefSP[i] + 1LL * strategy[i] * prices[i];
        }

        long long originalProfit = prefSP[n];

        long long bestDelta = 0; // we can choose "no modification"
        for (int l = 0; l + k <= n; l++) {
            long long secondHalfPrices = prefP[l + k] - prefP[l + h];
            long long windowOrig = prefSP[l + k] - prefSP[l];

            long long delta = secondHalfPrices - windowOrig;
            if (delta > bestDelta) bestDelta = delta;
        }

        return originalProfit + bestDelta;
    }
};
