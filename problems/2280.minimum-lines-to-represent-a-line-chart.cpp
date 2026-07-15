// @leetcode id=2280 questionId=2367 slug=minimum-lines-to-represent-a-line-chart lang=cpp site=leetcode.com title="Minimum Lines to Represent a Line Chart"
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if (n == 1) return 0;

        sort(stockPrices.begin(), stockPrices.end());

        int count = 0;
        long long prevDx = 0, prevDy = 0;
        for (int i = 1; i < n; i++) {
            long long dx = stockPrices[i][0] - stockPrices[i - 1][0];
            long long dy = stockPrices[i][1] - stockPrices[i - 1][1];
            long long g = gcd(dx, llabs(dy));
            if (g == 0) g = 1;
            long long ndx = dx / g, ndy = dy / g;

            if (i == 1 || ndx != prevDx || ndy != prevDy) {
                count++;
                prevDx = ndx;
                prevDy = ndy;
            }
        }
        return count;
    }
};
