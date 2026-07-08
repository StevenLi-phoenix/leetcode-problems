// @leetcode id=54 questionId=54 slug=spiral-matrix lang=cpp site=leetcode.com title="Spiral Matrix"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> result;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; ++c) result.push_back(matrix[top][c]);
            ++top;
            for (int r = top; r <= bottom; ++r) result.push_back(matrix[r][right]);
            --right;
            if (top <= bottom) {
                for (int c = right; c >= left; --c) result.push_back(matrix[bottom][c]);
                --bottom;
            }
            if (left <= right) {
                for (int r = bottom; r >= top; --r) result.push_back(matrix[r][left]);
                ++left;
            }
        }
        return result;
    }
};
