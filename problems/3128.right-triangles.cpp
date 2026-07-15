// @leetcode id=3128 questionId=3388 slug=right-triangles lang=cpp site=leetcode.com title="Right Triangles"
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<long long> rowCount(rows, 0), colCount(cols, 0);
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }

        long long total = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    total += (rowCount[r] - 1) * (colCount[c] - 1);
                }
            }
        }
        return total;
    }
};
