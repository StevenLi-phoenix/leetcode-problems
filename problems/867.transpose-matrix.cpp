// @leetcode id=867 questionId=898 slug=transpose-matrix lang=cpp site=leetcode.com title="Transpose Matrix"
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans[j][i] = matrix[i][j];
        return ans;
    }
};
