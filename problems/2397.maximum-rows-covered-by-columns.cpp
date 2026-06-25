// @leetcode id=2397 questionId=2482 slug=maximum-rows-covered-by-columns lang=cpp site=leetcode.com title="Maximum Rows Covered by Columns"
class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row_masks(m, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    row_masks[i] |= (1 << j);
                }
            }
        }

        int ans = 0;

        function<void(int, int, int)> dfs = [&](int col, int count, int mask) {
            if (count == numSelect) {
                int covered = 0;
                for (int i = 0; i < m; i++) {
                    if ((row_masks[i] & mask) == row_masks[i]) {
                        covered++;
                    }
                }
                ans = max(ans, covered);
                return;
            }

            if (col == n || n - col + count < numSelect) return;

            dfs(col + 1, count + 1, mask | (1 << col));
            dfs(col + 1, count, mask);
        };

        dfs(0, 0, 0);
        return ans;
    }
};
