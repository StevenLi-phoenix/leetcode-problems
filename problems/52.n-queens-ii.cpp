// @leetcode id=52 questionId=52 slug=n-queens-ii lang=cpp site=leetcode.com title="N-Queens II"
class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> usedCol(n, false), usedDiag1(2 * n, false), usedDiag2(2 * n, false);
        int count = 0;

        function<void(int)> dfs = [&](int row) {
            if (row == n) {
                ++count;
                return;
            }

            for (int col = 0; col < n; ++col) {
                int d1 = row - col + n, d2 = row + col;
                if (usedCol[col] || usedDiag1[d1] || usedDiag2[d2]) continue;

                usedCol[col] = usedDiag1[d1] = usedDiag2[d2] = true;
                dfs(row + 1);
                usedCol[col] = usedDiag1[d1] = usedDiag2[d2] = false;
            }
        };

        dfs(0);
        return count;
    }
};
