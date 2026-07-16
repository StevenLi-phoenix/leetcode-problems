// @leetcode id=3946 questionId=3742 slug=maximum-number-of-items-from-sale-i lang=cpp site=leetcode.com title="Maximum Number of Items From Sale I"
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int maxFactor = 0;
        int minPrice = INT_MAX;
        for (auto& it : items) {
            maxFactor = max(maxFactor, it[0]);
            minPrice = min(minPrice, it[1]);
        }

        vector<int> cnt(maxFactor + 1, 0);
        for (auto& it : items) cnt[it[0]]++;

        vector<long long> value(maxFactor + 1, 0);
        for (int v = 1; v <= maxFactor; v++) {
            for (int u = v; u <= maxFactor; u += v) {
                value[v] += cnt[u];
            }
        }

        vector<long long> dp(budget + 1, 0);
        for (auto& it : items) {
            int cost = it[1];
            long long val = value[it[0]];
            if (cost > budget) continue;
            for (int b = budget; b >= cost; b--) {
                dp[b] = max(dp[b], dp[b - cost] + val);
            }
        }

        long long best = 0;
        for (int b = 0; b <= budget; b++) {
            long long total = dp[b] + (long long)(budget - b) / minPrice;
            best = max(best, total);
        }
        return (int)best;
    }
};
