// @leetcode id=2556 questionId=2641 slug=disconnect-path-in-a-binary-matrix-by-at-most-one-flip lang=cpp site=leetcode.com title="Disconnect Path in a Binary Matrix by at Most One Flip"
class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> reachF(m, vector<bool>(n, false));
        vector<vector<bool>> reachB(m, vector<bool>(n, false));

        if (grid[0][0] == 1) {
            reachF[0][0] = true;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0 && j == 0) continue;
                    if (grid[i][j] != 1) continue;
                    bool fromTop = (i > 0) && reachF[i - 1][j];
                    bool fromLeft = (j > 0) && reachF[i][j - 1];
                    reachF[i][j] = fromTop || fromLeft;
                }
            }
        }

        if (!reachF[m - 1][n - 1]) return true;

        reachB[m - 1][n - 1] = true;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                if (grid[i][j] != 1) continue;
                bool fromBottom = (i < m - 1) && reachB[i + 1][j];
                bool fromRight = (j < n - 1) && reachB[i][j + 1];
                reachB[i][j] = fromBottom || fromRight;
            }
        }

        for (int d = 1; d <= m + n - 3; d++) {
            int count = 0;
            for (int i = 0; i < m; i++) {
                int j = d - i;
                if (j < 0 || j >= n) continue;
                if (reachF[i][j] && reachB[i][j]) count++;
            }
            if (count == 1) return true;
        }
        return false;
    }
};
