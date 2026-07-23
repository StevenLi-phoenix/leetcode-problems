// @leetcode id=3033 questionId=3330 slug=modify-the-matrix lang=cpp site=leetcode.com title="Modify the Matrix"
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> colMax(n, -1);

        for (int c = 0; c < n; c++) {
            for (int r = 0; r < m; r++) {
                colMax[c] = max(colMax[c], matrix[r][c]);
            }
        }

        vector<vector<int>> answer = matrix;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (answer[r][c] == -1) answer[r][c] = colMax[c];
            }
        }
        return answer;
    }
};
