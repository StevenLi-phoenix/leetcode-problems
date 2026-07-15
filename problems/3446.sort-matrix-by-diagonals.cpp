// @leetcode id=3446 questionId=3748 slug=sort-matrix-by-diagonals lang=cpp site=leetcode.com title="Sort Matrix by Diagonals"
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Bottom-left triangle (including middle diagonal): start row from 0..n-1, col=0, non-increasing.
        for (int startRow = 0; startRow < n; startRow++) {
            vector<int> diag;
            for (int r = startRow, c = 0; r < n && c < n; r++, c++) diag.push_back(grid[r][c]);
            sort(diag.begin(), diag.end(), greater<int>());
            int idx = 0;
            for (int r = startRow, c = 0; r < n && c < n; r++, c++) grid[r][c] = diag[idx++];
        }

        // Top-right triangle: start col from 1..n-1, row=0, non-decreasing.
        for (int startCol = 1; startCol < n; startCol++) {
            vector<int> diag;
            for (int r = 0, c = startCol; r < n && c < n; r++, c++) diag.push_back(grid[r][c]);
            sort(diag.begin(), diag.end());
            int idx = 0;
            for (int r = 0, c = startCol; r < n && c < n; r++, c++) grid[r][c] = diag[idx++];
        }

        return grid;
    }
};
