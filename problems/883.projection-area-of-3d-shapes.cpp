// @leetcode id=883 questionId=919 slug=projection-area-of-3d-shapes lang=cpp site=leetcode.com title="Projection Area of 3D Shapes"
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;
        for (int i = 0; i < n; i++) {
            int rowMax = 0, colMax = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) area++; // top view
                rowMax = max(rowMax, grid[i][j]);
                colMax = max(colMax, grid[j][i]);
            }
            area += rowMax + colMax;
        }
        return area;
    }
};
