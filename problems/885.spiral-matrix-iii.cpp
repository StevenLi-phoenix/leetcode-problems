// @leetcode id=885 questionId=921 slug=spiral-matrix-iii lang=cpp site=leetcode.com title="Spiral Matrix III"
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int total = rows * cols;
        int r = rStart, c = cStart;
        result.push_back({r, c});

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int dir = 0;
        int steps = 1;

        while ((int)result.size() < total) {
            for (int rep = 0; rep < 2 && (int)result.size() < total; rep++) {
                for (int i = 0; i < steps && (int)result.size() < total; i++) {
                    r += dr[dir];
                    c += dc[dir];
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result.push_back({r, c});
                    }
                }
                dir = (dir + 1) % 4;
            }
            steps++;
        }
        return result;
    }
};
