// @leetcode id=934 questionId=971 slug=shortest-bridge lang=cpp site=leetcode.com title="Shortest Bridge"
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        // Find the first island via iterative DFS and seed the BFS queue.
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] != 1) continue;
                found = true;
                stack<pair<int, int>> st;
                st.push({i, j});
                dist[i][j] = 0;
                while (!st.empty()) {
                    auto [r, c] = st.top(); st.pop();
                    q.push({r, c});
                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                        if (grid[nr][nc] == 1 && dist[nr][nc] == -1) {
                            dist[nr][nc] = 0;
                            st.push({nr, nc});
                        }
                    }
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if (dist[nr][nc] != -1) continue;
                if (grid[nr][nc] == 1) return dist[r][c]; // reached the second island
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
        return -1;
    }
};
