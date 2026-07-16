// @leetcode id=1139 questionId=1239 slug=largest-1-bordered-square lang=cpp site=leetcode.com title="Largest 1-Bordered Square"
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> left(rows, vector<int>(cols, 0));
        vector<vector<int>> up(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                    up[i][j] = (i == 0 ? 0 : up[i - 1][j]) + 1;
                }
            }
        }

        int best = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) continue;
                int maxSize = min(left[i][j], up[i][j]);
                for (int size = maxSize; size >= 1; size--) {
                    int r1 = i - size + 1, c1 = j - size + 1;
                    if (r1 < 0 || c1 < 0) continue;
                    if (left[r1][j] >= size && up[i][c1] >= size) {
                        best = max(best, size);
                        break;
                    }
                }
            }
        }
        return best * best;
    }
};
