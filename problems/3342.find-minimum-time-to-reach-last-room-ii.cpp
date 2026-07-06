// @leetcode id=3342 questionId=3628 slug=find-minimum-time-to-reach-last-room-ii lang=cpp site=leetcode.com title="Find Minimum Time to Reach Last Room II"
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<array<long long, 2>>> dist(n, vector<array<long long, 2>>(m, {LLONG_MAX, LLONG_MAX}));
        dist[0][0][0] = 0;

        using State = tuple<long long, int, int, int>; // time, r, c, parity
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, 0, 0, 0});

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto [t, r, c, p] = pq.top();
            pq.pop();
            if (t > dist[r][c][p]) continue;
            if (r == n - 1 && c == m - 1) return (int)t;

            long long cost = (p == 0) ? 1 : 2;
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                long long arrival = max(t, (long long)moveTime[nr][nc]) + cost;
                int np = 1 - p;
                if (arrival < dist[nr][nc][np]) {
                    dist[nr][nc][np] = arrival;
                    pq.push({arrival, nr, nc, np});
                }
            }
        }
        return (int)min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
    }
};
