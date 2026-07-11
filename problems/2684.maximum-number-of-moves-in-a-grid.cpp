// @leetcode id=2684 questionId=2794 slug=maximum-number-of-moves-in-a-grid lang=cpp site=leetcode.com title="Maximum Number of Moves in a Grid"
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<bool> reachable(m, true), nxt(m);
        for (int col = 0; col + 1 < n; col++) {
            bool moved = false;
            fill(nxt.begin(), nxt.end(), false);
            for (int row = 0; row < m; row++) {
                if (!reachable[row]) continue;
                for (int dr = -1; dr <= 1; dr++) {
                    int r = row + dr;
                    if (r < 0 || r >= m) continue;
                    if (grid[r][col + 1] > grid[row][col]) {
                        nxt[r] = true;
                        moved = true;
                    }
                }
            }
            if (!moved) return col;
            swap(reachable, nxt);
        }
        return n - 1;
    }
};
