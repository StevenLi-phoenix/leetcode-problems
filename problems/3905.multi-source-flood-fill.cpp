// @leetcode id=3905 questionId=4283 slug=multi-source-flood-fill lang=cpp site=leetcode.com title="Multi Source Flood Fill"
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (auto& s : sources) {
            grid[s[0]][s[1]] = s[2];
            q.push({s[0], s[1]});
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int levelSize = q.size();
            vector<vector<int>> updates;
            unordered_map<long long, int> best;

            for (int i = 0; i < levelSize; i++) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if (grid[nr][nc] != 0) continue;
                    long long key = (long long)nr * m + nc;
                    auto it = best.find(key);
                    if (it == best.end() || grid[r][c] > it->second) {
                        best[key] = grid[r][c];
                    }
                }
            }

            for (auto& [key, color] : best) {
                int nr = key / m, nc = key % m;
                grid[nr][nc] = color;
                q.push({nr, nc});
            }
        }

        return grid;
    }
};
