// @leetcode id=840 questionId=870 slug=magic-squares-in-grid lang=cpp site=leetcode.com title="Magic Squares In Grid"
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int R = (int)grid.size();
        int C = (int)grid[0].size();
        if (R < 3 || C < 3) return 0;

        auto isMagic = [&](int r, int c) -> bool {
            // center must be 5 for 1..9 magic square
            if (grid[r + 1][c + 1] != 5) return false;

            bool seen[10] = {false}; // indices 1..9
            for (int i = r; i < r + 3; i++) {
                for (int j = c; j < c + 3; j++) {
                    int v = grid[i][j];
                    if (v < 1 || v > 9) return false;
                    if (seen[v]) return false;
                    seen[v] = true;
                }
            }

            // rows
            for (int i = 0; i < 3; i++) {
                int s = grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2];
                if (s != 15) return false;
            }
            // cols
            for (int j = 0; j < 3; j++) {
                int s = grid[r][c + j] + grid[r + 1][c + j] + grid[r + 2][c + j];
                if (s != 15) return false;
            }
            // diagonals
            int d1 = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
            int d2 = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];
            return d1 == 15 && d2 == 15;
        };

        int ans = 0;
        for (int r = 0; r + 2 < R; r++) {
            for (int c = 0; c + 2 < C; c++) {
                if (isMagic(r, c)) ans++;
            }
        }
        return ans;
    }
};
