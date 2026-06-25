// @leetcode id=3286 questionId=3558 slug=find-a-safe-walk-through-a-grid lang=cpp site=leetcode.com title="Find a Safe Walk Through a Grid"
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        // BFS with priority queue (0-1 BFS via deque)
        // dist[i][j] = minimum damage to reach (i,j)
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        deque<pair<int,int>> dq;
        if (grid[0][0] == 0) dq.push_front({0, 0});
        else dq.push_back({0, 0});
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int newDist = dist[x][y] + grid[nx][ny];
                if (newDist < dist[nx][ny]) {
                    dist[nx][ny] = newDist;
                    if (grid[nx][ny] == 0) dq.push_front({nx, ny});
                    else dq.push_back({nx, ny});
                }
            }
        }
        
        return health - dist[m-1][n-1] >= 1;
    }
};
