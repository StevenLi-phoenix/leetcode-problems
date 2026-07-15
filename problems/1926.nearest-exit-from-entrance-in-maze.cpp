// @leetcode id=1926 questionId=2038 slug=nearest-exit-from-entrance-in-maze lang=cpp site=leetcode.com title="Nearest Exit from Entrance in Maze"
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            steps++;
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (visited[nr][nc] || maze[nr][nc] == '+') continue;
                    if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) return steps;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};
