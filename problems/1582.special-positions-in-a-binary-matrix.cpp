// @leetcode id=1582 questionId=1704 slug=special-positions-in-a-binary-matrix lang=cpp site=leetcode.com title="Special Positions in a Binary Matrix"
class Solution {
    public:
    int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size(), ans = 0;
    vector<int> rowSum(m, 0), colSum(n, 0);
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) { rowSum[i] += mat[i][j]; colSum[j] += mat[i][j]; }
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) ans++;
    return ans;
    }
    };
