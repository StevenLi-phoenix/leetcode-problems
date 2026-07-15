// @leetcode id=3341 questionId=3627 slug=find-minimum-time-to-reach-last-room-i lang=cpp site=leetcode.com title="Find Minimum Time to Reach Last Room I"
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<long long>> dist(n, vector<long long>(m, LLONG_MAX));
        dist[0][0] = 0;

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [d, r, c] = pq.top(); pq.pop();
            if (d > dist[r][c]) continue;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                long long nd = max(d, (long long)moveTime[nr][nc]) + 1;
                if (nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    pq.push({nd, nr, nc});
                }
            }
        }

        return (int)dist[n - 1][m - 1];
    }
};
