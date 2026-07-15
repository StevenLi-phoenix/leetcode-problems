// @leetcode id=3239 questionId=3526 slug=minimum-number-of-flips-to-make-binary-grid-palindromic-i lang=cpp site=leetcode.com title="Minimum Number of Flips to Make Binary Grid Palindromic I"
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int rowFlips = 0;
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1;
            while (l < r) {
                if (grid[i][l] != grid[i][r]) rowFlips++;
                l++;
                r--;
            }
        }

        int colFlips = 0;
        for (int j = 0; j < n; j++) {
            int t = 0, b = m - 1;
            while (t < b) {
                if (grid[t][j] != grid[b][j]) colFlips++;
                t++;
                b--;
            }
        }

        return min(rowFlips, colFlips);
    }
};
