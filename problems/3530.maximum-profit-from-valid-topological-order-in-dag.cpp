// @leetcode id=3530 questionId=3826 slug=maximum-profit-from-valid-topological-order-in-dag lang=cpp site=leetcode.com title="Maximum Profit from Valid Topological Order in DAG"
class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        // dp[mask] = best profit from placing exactly the nodes in mask as
        // the first popcount(mask) positions. A node can be placed last in
        // mask only if every one of its prerequisites is already present.
        vector<int> prereq(n, 0);
        for (auto& e : edges) prereq[e[1]] |= (1 << e[0]);

        int full = 1 << n;
        vector<long long> dp(full, -1);
        dp[0] = 0;

        for (int mask = 1; mask < full; mask++) {
            int pos = __builtin_popcount(mask);
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) continue;
                int prev = mask ^ (1 << i);
                if ((prereq[i] & prev) != prereq[i]) continue;
                if (dp[prev] < 0) continue;
                long long candidate = dp[prev] + (long long)score[i] * pos;
                if (candidate > dp[mask]) dp[mask] = candidate;
            }
        }
        return (int)dp[full - 1];
    }
};
