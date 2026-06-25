// @leetcode id=2906 questionId=3031 slug=construct-product-matrix lang=cpp site=leetcode.com title="Construct Product Matrix"
class Solution {
    public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    const int MOD = 12345;
    long long total = n * m;
    vector<long long> pre(total + 1, 1), suf(total + 1, 1);
    for (int i = 0; i < total; i++)
    pre[i+1] = pre[i] * (grid[i/m][i%m] % MOD) % MOD;
    for (int i = total - 1; i >= 0; i--)
    suf[i] = suf[i+1] * (grid[i/m][i%m] % MOD) % MOD;
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < total; i++)
    res[i/m][i%m] = pre[i] * suf[i+1] % MOD;
    return res;
    }
    };
