// @leetcode id=3562 questionId=3854 slug=maximum-profit-from-trading-stocks-with-discounts lang=cpp site=leetcode.com title="Maximum Profit from Trading Stocks with Discounts"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> children(n + 1);
        for (auto &e : hierarchy) {
            int u = e[0], v = e[1];
            children[u].push_back(v);
        }

        const int NEG = -1e9;
        // dp[u][p] is a vector<int> of size budget+1
        vector<array<vector<int>, 2>> dp(n + 1);

        auto mergeKnapsack = [&](const vector<int>& A, const vector<int>& B) {
            vector<int> C(budget + 1, NEG);
            for (int i = 0; i <= budget; i++) if (A[i] > NEG) {
                for (int j = 0; j + i <= budget; j++) if (B[j] > NEG) {
                    C[i + j] = max(C[i + j], A[i] + B[j]);
                }
            }
            return C;
        };

        function<void(int)> dfs = [&](int u) {
            for (int v : children[u]) dfs(v);

            for (int p = 0; p <= 1; p++) {
                // Option 1: don't buy u
                vector<int> noBuy(budget + 1, NEG);
                noBuy[0] = 0;
                for (int v : children[u]) {
                    noBuy = mergeKnapsack(noBuy, dp[v][0]); // parent (u) not bought
                }

                // Option 2: buy u
                vector<int> buy(budget + 1, NEG);
                int baseCost = present[u - 1];
                int cost = (p ? baseCost / 2 : baseCost);
                if (cost <= budget) {
                    buy[cost] = future[u - 1] - cost;
                }
                for (int v : children[u]) {
                    buy = mergeKnapsack(buy, dp[v][1]); // parent (u) bought
                }

                dp[u][p].assign(budget + 1, NEG);
                for (int b = 0; b <= budget; b++) {
                    dp[u][p][b] = max(noBuy[b], buy[b]);
                }
            }
        };

        dfs(1);

        int ans = 0;
        for (int b = 0; b <= budget; b++) ans = max(ans, dp[1][0][b]);
        return ans;
    }
};
