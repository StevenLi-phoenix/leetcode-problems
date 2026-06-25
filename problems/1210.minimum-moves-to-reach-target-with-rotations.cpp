// @leetcode id=1210 questionId=1322 slug=minimum-moves-to-reach-target-with-rotations lang=cpp site=leetcode.com title="Minimum Moves to Reach Target with Rotations"
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        // State: (row, col, dir) where (row,col) is tail position
        // dir=0: horizontal (tail at r,c, head at r,c+1)
        // dir=1: vertical (tail at r,c, head at r+1,c)
        
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(2, INT_MAX)));
        queue<tuple<int,int,int>> q;
        dist[0][0][0] = 0;
        q.push({0, 0, 0});
        
        while (!q.empty()) {
            auto [r, c, d] = q.front(); q.pop();
            int cur = dist[r][c][d];
            
            if (d == 0) { // horizontal: tail at (r,c), head at (r,c+1)
                // Move right: need (r,c+2) empty
                if (c+2 < n && grid[r][c+2] == 0) {
                    if (dist[r][c+1][0] == INT_MAX) {
                        dist[r][c+1][0] = cur + 1;
                        q.push({r, c+1, 0});
                    }
                }
                // Move down: need (r+1,c) and (r+1,c+1) empty
                if (r+1 < n && grid[r+1][c] == 0 && grid[r+1][c+1] == 0) {
                    if (dist[r+1][c][0] == INT_MAX) {
                        dist[r+1][c][0] = cur + 1;
                        q.push({r+1, c, 0});
                    }
                    // Rotate clockwise: horizontal -> vertical
                    if (dist[r][c][1] == INT_MAX) {
                        dist[r][c][1] = cur + 1;
                        q.push({r, c, 1});
                    }
                }
            } else { // vertical: tail at (r,c), head at (r+1,c)
                // Move down: need (r+2,c) empty
                if (r+2 < n && grid[r+2][c] == 0) {
                    if (dist[r+1][c][1] == INT_MAX) {
                        dist[r+1][c][1] = cur + 1;
                        q.push({r+1, c, 1});
                    }
                }
                // Move right: need (r,c+1) and (r+1,c+1) empty
                if (c+1 < n && grid[r][c+1] == 0 && grid[r+1][c+1] == 0) {
                    if (dist[r][c+1][1] == INT_MAX) {
                        dist[r][c+1][1] = cur + 1;
                        q.push({r, c+1, 1});
                    }
                    // Rotate counterclockwise: vertical -> horizontal
                    if (dist[r][c][0] == INT_MAX) {
                        dist[r][c][0] = cur + 1;
                        q.push({r, c, 0});
                    }
                }
            }
        }
        
        int ans = dist[n-1][n-2][0];
        return ans == INT_MAX ? -1 : ans;
    }
};
