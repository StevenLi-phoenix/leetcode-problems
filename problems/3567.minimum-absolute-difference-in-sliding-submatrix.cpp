// @leetcode id=3567 questionId=3884 slug=minimum-absolute-difference-in-sliding-submatrix lang=cpp site=leetcode.com title="Minimum Absolute Difference in Sliding Submatrix"
class Solution {
    public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));
    for (int i = 0; i <= m-k; i++) {
    for (int j = 0; j <= n-k; j++) {
    vector<int> vals;
    for (int r = i; r < i+k; r++)
    for (int c = j; c < j+k; c++)
    vals.push_back(grid[r][c]);
    sort(vals.begin(), vals.end());
    int mn = INT_MAX;
    for (int t = 1; t < (int)vals.size(); t++)
    if (vals[t] != vals[t-1])
    mn = min(mn, vals[t] - vals[t-1]);
    ans[i][j] = (mn == INT_MAX) ? 0 : mn;
    }
    }
    return ans;
    }
    };
