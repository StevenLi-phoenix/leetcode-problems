// @leetcode id=3933 questionId=3802 slug=largest-local-values-in-a-matrix-ii lang=cpp site=leetcode.com title="Largest Local Values in a Matrix II"
class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        int logN = 1, logM = 1;
        while ((1 << logN) <= n) logN++;
        while ((1 << logM) <= m) logM++;

        vector<vector<vector<vector<int>>>> sparse(
            logN, vector<vector<vector<int>>>(logM, vector<vector<int>>(n, vector<int>(m))));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                sparse[0][0][i][j] = matrix[i][j];

        for (int k2 = 1; k2 < logM; k2++) {
            int len = 1 << (k2 - 1);
            for (int i = 0; i < n; i++)
                for (int j = 0; j + (1 << k2) <= m; j++)
                    sparse[0][k2][i][j] = max(sparse[0][k2 - 1][i][j], sparse[0][k2 - 1][i][j + len]);
        }
        for (int k1 = 1; k1 < logN; k1++) {
            int len = 1 << (k1 - 1);
            for (int k2 = 0; k2 < logM; k2++) {
                for (int i = 0; i + (1 << k1) <= n; i++)
                    for (int j = 0; j + (1 << k2) <= m; j++)
                        sparse[k1][k2][i][j] = max(sparse[k1 - 1][k2][i][j], sparse[k1 - 1][k2][i + len][j]);
            }
        }

        auto query = [&](int r1, int c1, int r2, int c2) -> int {
            int k1 = 0; while ((1 << (k1 + 1)) <= r2 - r1 + 1) k1++;
            int k2 = 0; while ((1 << (k2 + 1)) <= c2 - c1 + 1) k2++;
            int a = sparse[k1][k2][r1][c1];
            int b = sparse[k1][k2][r1][c2 - (1 << k2) + 1];
            int c = sparse[k1][k2][r2 - (1 << k1) + 1][c1];
            int d = sparse[k1][k2][r2 - (1 << k1) + 1][c2 - (1 << k2) + 1];
            return max({a, b, c, d});
        };

        int count = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                int x = matrix[row][col];
                if (x == 0) continue;

                int r1 = max(0, row - x), r2 = min(n - 1, row + x);
                int c1 = max(0, col - x), c2 = min(m - 1, col + x);

                int fullMax = query(r1, c1, r2, c2);
                if (fullMax <= x) { count++; continue; }

                bool excludeTopRow = (row - x >= 0);
                bool excludeBottomRow = (row + x <= n - 1);
                bool excludeLeftCol = (col - x >= 0);
                bool excludeRightCol = (col + x <= m - 1);

                vector<int> pieces;
                int middleStart = r1, middleEnd = r2;

                if (excludeTopRow) {
                    int lo = c1 + (excludeLeftCol ? 1 : 0);
                    int hi = c2 - (excludeRightCol ? 1 : 0);
                    if (lo <= hi) pieces.push_back(query(r1, lo, r1, hi));
                    middleStart = r1 + 1;
                }
                if (excludeBottomRow) {
                    int lo = c1 + (excludeLeftCol ? 1 : 0);
                    int hi = c2 - (excludeRightCol ? 1 : 0);
                    if (lo <= hi) pieces.push_back(query(r2, lo, r2, hi));
                    middleEnd = r2 - 1;
                }
                if (middleStart <= middleEnd) {
                    pieces.push_back(query(middleStart, c1, middleEnd, c2));
                }

                int excludedMax = INT_MIN;
                for (int p : pieces) excludedMax = max(excludedMax, p);

                if (pieces.empty() || excludedMax <= x) count++;
            }
        }
        return count;
    }
};
