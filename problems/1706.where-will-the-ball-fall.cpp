// @leetcode id=1706 questionId=1324 slug=where-will-the-ball-fall lang=cpp site=leetcode.com title="Where Will the Ball Fall"
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        for (int start = 0; start < n; start++) {
            int col = start;
            for (int row = 0; row < m; row++) {
                int dir = grid[row][col];
                int nextCol = col + dir;
                if (nextCol < 0 || nextCol >= n || grid[row][nextCol] != dir) {
                    col = -1;
                    break;
                }
                col = nextCol;
            }
            ans[start] = col;
        }
        return ans;
    }
};
