// @leetcode id=1594 questionId=1716 slug=maximum-non-negative-product-in-a-matrix lang=cpp site=leetcode.com title="Maximum Non Negative Product in a Matrix"
class Solution {
    public:
    int maxProductPath(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    const int MOD = 1e9 + 7;
    vector<vector<long long>> mx(m, vector<long long>(n)), mn(m, vector<long long>(n));
    mx[0][0] = mn[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) mx[i][0] = mn[i][0] = mx[i-1][0] * grid[i][0];
    for (int j = 1; j < n; j++) mx[0][j] = mn[0][j] = mx[0][j-1] * grid[0][j];
    for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
    long long v = grid[i][j];
    long long a = mx[i-1][j]*v, b = mn[i-1][j]*v, c = mx[i][j-1]*v, d = mn[i][j-1]*v;
    mx[i][j] = max({a,b,c,d});
    mn[i][j] = min({a,b,c,d});
    }
    }
    return mx[m-1][n-1] < 0 ? -1 : mx[m-1][n-1] % MOD;
    }
    };
