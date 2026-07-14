// @leetcode id=2711 questionId=2801 slug=difference-of-number-of-distinct-values-on-diagonals lang=cpp site=leetcode.com title="Difference of Number of Distinct Values on Diagonals"
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> answer(m, vector<int>(n, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                unordered_set<int> above;
                for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) above.insert(grid[i][j]);
                unordered_set<int> below;
                for (int i = r + 1, j = c + 1; i < m && j < n; i++, j++) below.insert(grid[i][j]);
                answer[r][c] = abs((int)above.size() - (int)below.size());
            }
        }
        return answer;
    }
};
