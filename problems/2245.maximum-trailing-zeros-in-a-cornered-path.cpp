// @leetcode id=2245 questionId=2363 slug=maximum-trailing-zeros-in-a-cornered-path lang=cpp site=leetcode.com title="Maximum Trailing Zeros in a Cornered Path"
class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        auto countFactor = [](int x, int f) {
            int c = 0;
            while (x % f == 0) { x /= f; c++; }
            return c;
        };

        vector<vector<int>> c2(m, vector<int>(n)), c5(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                c2[i][j] = countFactor(grid[i][j], 2);
                c5[i][j] = countFactor(grid[i][j], 5);
            }
        }

        auto buildDirSums = [&](vector<vector<int>>& c) {
            vector<vector<int>> left(m, vector<int>(n)), right(m, vector<int>(n));
            vector<vector<int>> up(m, vector<int>(n)), down(m, vector<int>(n));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    left[i][j] = c[i][j] + (j > 0 ? left[i][j - 1] : 0);
                }
                for (int j = n - 1; j >= 0; j--) {
                    right[i][j] = c[i][j] + (j < n - 1 ? right[i][j + 1] : 0);
                }
            }
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < m; i++) {
                    up[i][j] = c[i][j] + (i > 0 ? up[i - 1][j] : 0);
                }
                for (int i = m - 1; i >= 0; i--) {
                    down[i][j] = c[i][j] + (i < m - 1 ? down[i + 1][j] : 0);
                }
            }
            return array<vector<vector<int>>, 4>{left, right, up, down};
        };

        auto dir2 = buildDirSums(c2);
        auto dir5 = buildDirSums(c5);

        int best = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int combos2[4] = {
                    dir2[0][i][j] + dir2[2][i][j] - c2[i][j],
                    dir2[0][i][j] + dir2[3][i][j] - c2[i][j],
                    dir2[1][i][j] + dir2[2][i][j] - c2[i][j],
                    dir2[1][i][j] + dir2[3][i][j] - c2[i][j]
                };
                int combos5[4] = {
                    dir5[0][i][j] + dir5[2][i][j] - c5[i][j],
                    dir5[0][i][j] + dir5[3][i][j] - c5[i][j],
                    dir5[1][i][j] + dir5[2][i][j] - c5[i][j],
                    dir5[1][i][j] + dir5[3][i][j] - c5[i][j]
                };
                for (int k = 0; k < 4; k++) {
                    best = max(best, min(combos2[k], combos5[k]));
                }
            }
        }
        return best;
    }
};
