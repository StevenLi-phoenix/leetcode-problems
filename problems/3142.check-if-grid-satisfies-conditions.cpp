// @leetcode id=3142 questionId=3415 slug=check-if-grid-satisfies-conditions lang=cpp site=leetcode.com title="Check if Grid Satisfies Conditions"
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i + 1 < m && grid[i][j] != grid[i + 1][j]) return false;
                if (j + 1 < n && grid[i][j] == grid[i][j + 1]) return false;
            }
        return true;
    }
};
