// @leetcode id=240 questionId=240 slug=search-a-2d-matrix-ii lang=cpp site=leetcode.com title="Search a 2D Matrix II"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size() - 1;
        while (row < (int)matrix.size() && col >= 0) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};
