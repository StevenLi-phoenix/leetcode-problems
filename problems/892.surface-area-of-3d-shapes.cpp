// @leetcode id=892 questionId=928 slug=surface-area-of-3d-shapes lang=cpp site=leetcode.com title="Surface Area of 3D Shapes"
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                if (v == 0) continue;
                area += 2;
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    int neighbor = (ni >= 0 && ni < n && nj >= 0 && nj < n) ? grid[ni][nj] : 0;
                    area += max(0, v - neighbor);
                }
            }
        }
        return area;
    }
};
