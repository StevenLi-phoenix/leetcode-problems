// @leetcode id=3148 questionId=3391 slug=maximum-difference-score-in-a-grid lang=cpp site=leetcode.com title="Maximum Difference Score in a Grid"
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> M(m, vector<int>(n));
        long long best = LLONG_MIN;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long minPrior = LLONG_MAX;
                if (i > 0) minPrior = min(minPrior, (long long)M[i - 1][j]);
                if (j > 0) minPrior = min(minPrior, (long long)M[i][j - 1]);

                if (minPrior != LLONG_MAX) {
                    best = max(best, (long long)grid[i][j] - minPrior);
                }

                long long m2 = grid[i][j];
                if (i > 0) m2 = min(m2, (long long)M[i - 1][j]);
                if (j > 0) m2 = min(m2, (long long)M[i][j - 1]);
                M[i][j] = (int)m2;
            }
        }
        return (int)best;
    }
};
