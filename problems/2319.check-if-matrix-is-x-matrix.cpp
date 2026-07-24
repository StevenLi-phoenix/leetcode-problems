// @leetcode id=2319 questionId=2398 slug=check-if-matrix-is-x-matrix lang=cpp site=leetcode.com title="Check if Matrix Is X-Matrix"
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool onDiagonal = (i == j) || (i + j == n - 1);
                if (onDiagonal && grid[i][j] == 0) return false;
                if (!onDiagonal && grid[i][j] != 0) return false;
            }
        }
        return true;
    }
};
