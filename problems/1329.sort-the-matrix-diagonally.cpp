// @leetcode id=1329 questionId=1253 slug=sort-the-matrix-diagonally lang=cpp site=leetcode.com title="Sort the Matrix Diagonally"
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        // Group elements by diagonal (i - j)
        map<int, vector<int>> diags;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                diags[i - j].push_back(mat[i][j]);
        
        // Sort each diagonal
        for (auto& [key, v] : diags)
            sort(v.begin(), v.end());
        
        // Put back sorted values
        map<int, int> idx;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                mat[i][j] = diags[key][idx[key]++];
            }
        }
        
        return mat;
    }
};
