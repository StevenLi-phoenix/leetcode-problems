// @leetcode id=2503 questionId=2588 slug=maximum-number-of-points-from-grid-queries lang=cpp site=leetcode.com title="Maximum Number of Points From Grid Queries"
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();

        vector<int> order(k);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) { return queries[a] < queries[b]; });

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        vector<int> answer(k);
        long long count = 0;

        for (int idx : order) {
            int q = queries[idx];
            while (!pq.empty() && get<0>(pq.top()) < q) {
                auto [val, r, c] = pq.top();
                pq.pop();
                count++;
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) continue;
                    visited[nr][nc] = true;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
            answer[idx] = (int)count;
        }

        return answer;
    }
};
