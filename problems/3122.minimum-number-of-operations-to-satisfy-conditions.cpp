// @leetcode id=3122 questionId=3404 slug=minimum-number-of-operations-to-satisfy-conditions lang=cpp site=leetcode.com title="Minimum Number of Operations to Satisfy Conditions"
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(n, vector<int>(10, 0));
        for (int j = 0; j < n; j++) {
            vector<int> freq(10, 0);
            for (int i = 0; i < m; i++) freq[grid[i][j]]++;
            for (int v = 0; v < 10; v++) cost[j][v] = m - freq[v];
        }

        vector<int> dp = cost[0];
        for (int j = 1; j < n; j++) {
            vector<int> ndp(10, INT_MAX);
            for (int v = 0; v < 10; v++) {
                int best = INT_MAX;
                for (int pv = 0; pv < 10; pv++) {
                    if (pv == v) continue;
                    best = min(best, dp[pv]);
                }
                ndp[v] = best + cost[j][v];
            }
            dp = ndp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
