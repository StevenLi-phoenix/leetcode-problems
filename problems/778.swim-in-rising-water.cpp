// @leetcode id=778 questionId=794 slug=swim-in-rising-water lang=cpp site=leetcode.com title="Swim in Rising Water"
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        int best = 0;

        while (!pq.empty()) {
            auto [h, r, c] = pq.top();
            pq.pop();
            best = max(best, h);

            if (r == n - 1 && c == n - 1) return best;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) continue;
                visited[nr][nc] = true;
                pq.push({grid[nr][nc], nr, nc});
            }
        }

        return best;
    }
};
