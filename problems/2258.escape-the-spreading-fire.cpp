// @leetcode id=2258 questionId=2344 slug=escape-the-spreading-fire lang=cpp site=leetcode.com title="Escape the Spreading Fire"
class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int INF = INT_MAX;
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        vector<vector<int>> fireTime(m, vector<int>(n, INF));
        queue<pair<int,int>> fq;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fireTime[i][j] = 0;
                    fq.push({i, j});
                }
            }
        }
        while (!fq.empty()) {
            auto [r, c] = fq.front(); fq.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (grid[nr][nc] == 2) continue;
                if (fireTime[nr][nc] != INF) continue;
                fireTime[nr][nc] = fireTime[r][c] + 1;
                fq.push({nr, nc});
            }
        }

        vector<vector<int>> personTime(m, vector<int>(n, INF));
        personTime[0][0] = 0;
        queue<pair<int,int>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [r, c] = pq.front(); pq.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (grid[nr][nc] == 2) continue;
                if (personTime[nr][nc] != INF) continue;
                personTime[nr][nc] = personTime[r][c] + 1;
                pq.push({nr, nc});
            }
        }

        if (personTime[m-1][n-1] == INF) return -1;
        if (fireTime[m-1][n-1] == INF) return 1000000000;

        auto feasible = [&](long long t) -> bool {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<pair<int,int>> q;
            if (t >= fireTime[0][0]) return false;
            visited[0][0] = true;
            q.push({0,0});
            vector<vector<long long>> arrive(m, vector<long long>(n, -1));
            arrive[0][0] = t;
            while (!q.empty()) {
                auto [r,c] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r+dr[d], nc = c+dc[d];
                    if (nr<0||nr>=m||nc<0||nc>=n) continue;
                    if (grid[nr][nc]==2 || visited[nr][nc]) continue;
                    long long newTime = arrive[r][c] + 1;
                    bool isDest = (nr==m-1 && nc==n-1);
                    if (isDest) {
                        if (newTime > (long long)fireTime[nr][nc]) continue;
                    } else {
                        if (newTime >= (long long)fireTime[nr][nc]) continue;
                    }
                    visited[nr][nc] = true;
                    arrive[nr][nc] = newTime;
                    if (isDest) return true;
                    q.push({nr,nc});
                }
            }
            return false;
        };

        long long lo = 0, hi = (long long)fireTime[m-1][n-1];
        long long best = -1;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(mid)) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return (int)best;
    }
};
