// @leetcode id=3240 questionId=3524 slug=minimum-number-of-flips-to-make-binary-grid-palindromic-ii lang=cpp site=leetcode.com title="Minimum Number of Flips to Make Binary Grid Palindromic II"
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long cost = 0;

        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int ones = grid[i][j] + grid[i][n - 1 - j] + grid[m - 1 - i][j] + grid[m - 1 - i][n - 1 - j];
                cost += min(ones, 4 - ones);
            }
        }

        int x = 0;
        long long minDiff = LLONG_MAX;

        if (m % 2 == 1) {
            int mid = m / 2;
            for (int j = 0; j < n / 2; j++) {
                int ones = grid[mid][j] + grid[mid][n - 1 - j];
                long long cost0 = ones, cost1 = 2 - ones;
                if (cost1 < cost0) { cost += cost1; x++; }
                else { cost += cost0; }
                minDiff = min(minDiff, (long long)abs(cost1 - cost0));
            }
        }

        if (n % 2 == 1) {
            int mid = n / 2;
            for (int i = 0; i < m / 2; i++) {
                int ones = grid[i][mid] + grid[m - 1 - i][mid];
                long long cost0 = ones, cost1 = 2 - ones;
                if (cost1 < cost0) { cost += cost1; x++; }
                else { cost += cost0; }
                minDiff = min(minDiff, (long long)abs(cost1 - cost0));
            }
        }

        if (x % 2 == 1) cost += minDiff;

        if (m % 2 == 1 && n % 2 == 1) {
            cost += grid[m / 2][n / 2];
        }

        return (int)cost;
    }
};
