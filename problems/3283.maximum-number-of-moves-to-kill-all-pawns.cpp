// @leetcode id=3283 questionId=3560 slug=maximum-number-of-moves-to-kill-all-pawns lang=cpp site=leetcode.com title="Maximum Number of Moves to Kill All Pawns"
class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> dist;
    int n;

    int bfs(int sx, int sy, int tx, int ty) {
        vector<vector<int>> d(50, vector<int>(50, -1));
        d[sx][sy] = 0;
        queue<pair<int,int>> q;
        q.push({sx, sy});
        int dx[8] = {-2,-2,-1,-1,1,1,2,2};
        int dy[8] = {-1,1,-2,2,-2,2,-1,1};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == tx && y == ty) return d[x][y];
            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= 50 || ny < 0 || ny >= 50 || d[nx][ny] != -1) continue;
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return d[tx][ty];
    }

    int solve(int mask, int last) {
        if (mask == 0) return 0;
        if (memo[mask][last] != -1) return memo[mask][last];

        int capturedCount = n - __builtin_popcount(mask);
        bool aliceTurn = (capturedCount % 2 == 0);

        int best = aliceTurn ? INT_MIN : INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;
            int cost = dist[last][i + 1] + solve(mask & ~(1 << i), i + 1);
            if (aliceTurn) best = max(best, cost);
            else best = min(best, cost);
        }

        memo[mask][last] = best;
        return best;
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        n = positions.size();
        vector<pair<int,int>> pts;
        pts.push_back({kx, ky});
        for (auto& p : positions) pts.push_back({p[0], p[1]});

        int total = n + 1;
        dist.assign(total, vector<int>(total, 0));
        for (int i = 0; i < total; i++) {
            for (int j = i + 1; j < total; j++) {
                int d = bfs(pts[i].first, pts[i].second, pts[j].first, pts[j].second);
                dist[i][j] = dist[j][i] = d;
            }
        }

        memo.assign(1 << n, vector<int>(total, -1));

        return solve((1 << n) - 1, 0);
    }
};
