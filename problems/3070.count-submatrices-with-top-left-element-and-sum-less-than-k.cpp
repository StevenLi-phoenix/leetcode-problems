// @leetcode id=3070 questionId=3338 slug=count-submatrices-with-top-left-element-and-sum-less-than-k lang=cpp site=leetcode.com title="Count Submatrices with Top-Left Element and Sum Less Than k"
class Solution {
    public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
    if (i > 0) grid[i][j] += grid[i-1][j];
    if (j > 0) grid[i][j] += grid[i][j-1];
    if (i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
    if (grid[i][j] <= k) ans++;
    }
    return ans;
    }
    };
