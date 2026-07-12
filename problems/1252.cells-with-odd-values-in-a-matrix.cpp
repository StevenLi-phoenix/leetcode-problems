// @leetcode id=1252 questionId=1378 slug=cells-with-odd-values-in-a-matrix lang=cpp site=leetcode.com title="Cells with Odd Values in a Matrix"
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        // A cell's total increment count is (row hits) + (col hits); track
        // per-row and per-col hit counts instead of the full m*n matrix.
        vector<int> rowCount(m, 0), colCount(n, 0);
        for (auto& idx : indices) {
            rowCount[idx[0]]++;
            colCount[idx[1]]++;
        }

        int oddRows = count_if(rowCount.begin(), rowCount.end(), [](int x) { return x % 2; });
        int oddCols = count_if(colCount.begin(), colCount.end(), [](int x) { return x % 2; });

        // cell(r,c) is odd iff exactly one of rowCount[r], colCount[c] is odd.
        return oddRows * (n - oddCols) + (m - oddRows) * oddCols;
    }
};
