// @leetcode id=51 questionId=51 slug=n-queens lang=cpp site=leetcode.com title="N-Queens"
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queenCol(n, -1); // queenCol[row] = column
        vector<bool> usedCol(n, false), usedDiag1(2 * n, false), usedDiag2(2 * n, false);

        function<void(int)> dfs = [&](int row) {
            if (row == n) {
                vector<string> board(n, string(n, '.'));
                for (int r = 0; r < n; ++r) board[r][queenCol[r]] = 'Q';
                result.push_back(board);
                return;
            }

            for (int col = 0; col < n; ++col) {
                int d1 = row - col + n, d2 = row + col;
                if (usedCol[col] || usedDiag1[d1] || usedDiag2[d2]) continue;

                queenCol[row] = col;
                usedCol[col] = usedDiag1[d1] = usedDiag2[d2] = true;
                dfs(row + 1);
                usedCol[col] = usedDiag1[d1] = usedDiag2[d2] = false;
            }
        };

        dfs(0);
        return result;
    }
};
