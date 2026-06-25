// @leetcode id=3212 questionId=3492 slug=count-submatrices-with-equal-frequency-of-x-and-y lang=cpp site=leetcode.com title="Count Submatrices With Equal Frequency of X and Y"
class Solution {
    public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    vector<vector<int>> cx(m, vector<int>(n, 0)), cy(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
    cx[i][j] = (grid[i][j] == 'X');
    cy[i][j] = (grid[i][j] == 'Y');
    if (i > 0) { cx[i][j] += cx[i-1][j]; cy[i][j] += cy[i-1][j]; }
    if (j > 0) { cx[i][j] += cx[i][j-1]; cy[i][j] += cy[i][j-1]; }
    if (i > 0 && j > 0) { cx[i][j] -= cx[i-1][j-1]; cy[i][j] -= cy[i-1][j-1]; }
    if (cx[i][j] == cy[i][j] && cx[i][j] > 0) ans++;
    }
    return ans;
    }
    };
