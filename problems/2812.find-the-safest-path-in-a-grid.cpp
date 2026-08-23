// @leetcode id=2812 questionId=2914 slug=find-the-safest-path-in-a-grid lang=cpp site=leetcode.com title="Find the Safest Path in a Grid"
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Multi-source BFS from all thieves to compute min distance
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        // Binary search on safeness factor
        // Check if we can go from (0,0) to (n-1,n-1) with all cells having dist >= v
        auto canReach = [&](int v) -> bool {
            if (dist[0][0] < v || dist[n-1][n-1] < v) return false;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<pair<int,int>> bfsQ;
            bfsQ.push({0, 0});
            visited[0][0] = true;
            while (!bfsQ.empty()) {
                auto [x, y] = bfsQ.front();
                bfsQ.pop();
                if (x == n-1 && y == n-1) return true;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && dist[nx][ny] >= v) {
                        visited[nx][ny] = true;
                        bfsQ.push({nx, ny});
                    }
                }
            }
            return false;
        };
        
        int lo = 0, hi = n; // max possible safeness is n-1
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (canReach(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
