// @leetcode id=3573 questionId=3892 slug=best-time-to-buy-and-sell-stock-v lang=cpp site=leetcode.com title="Best Time to Buy and Sell Stock V"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // flat[j] = max profit with j completed transactions, no open position
        // longHold[j] = max profit with j completed transactions + currently holding long
        // shortHold[j] = max profit with j completed transactions + currently short-sold
        const long long NEG = -(1LL << 60);
        vector<long long> flat(k + 1, NEG), longHold(k + 1, NEG), shortHold(k + 1, NEG);
        flat[0] = 0;
        
        for (int p : prices) {
            vector<long long> nFlat = flat, nLong = longHold, nShort = shortHold;
            for (int j = 0; j <= k; j++) {
                // Open a long position: spend p
                if (flat[j] != NEG)
                    nLong[j] = max(nLong[j], flat[j] - p);
                // Open a short position: gain p
                if (flat[j] != NEG)
                    nShort[j] = max(nShort[j], flat[j] + p);
                // Close long position: sell at p, complete one transaction
                if (j > 0 && longHold[j-1] != NEG)
                    nFlat[j] = max(nFlat[j], longHold[j-1] + p);
                // Close short position: buy back at p, complete one transaction
                if (j > 0 && shortHold[j-1] != NEG)
                    nFlat[j] = max(nFlat[j], shortHold[j-1] - p);
            }
            flat = nFlat;
            longHold = nLong;
            shortHold = nShort;
        }
        
        long long ans = 0;
        for (int j = 0; j <= k; j++)
            if (flat[j] != NEG) ans = max(ans, flat[j]);
        return ans;
    }
};
