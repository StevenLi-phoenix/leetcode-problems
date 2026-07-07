// @leetcode id=59 questionId=59 slug=spiral-matrix-ii lang=cpp site=leetcode.com title="Spiral Matrix II"
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int val = 1;

        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; ++c) matrix[top][c] = val++;
            ++top;
            for (int r = top; r <= bottom; ++r) matrix[r][right] = val++;
            --right;
            for (int c = right; c >= left; --c) matrix[bottom][c] = val++;
            --bottom;
            for (int r = bottom; r >= top; --r) matrix[r][left] = val++;
            ++left;
        }
        return matrix;
    }
};
