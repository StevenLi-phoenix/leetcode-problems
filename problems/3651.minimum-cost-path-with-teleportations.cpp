// @leetcode id=3651 questionId=3889 slug=minimum-cost-path-with-teleportations lang=cpp site=leetcode.com title="Minimum Cost Path with Teleportations"
class Solution {
public:
int minCost(vector<vector<int>>& grid, int k) {
int m = grid.size(), n = grid[0].size();
int total = m*n;
int kk = min(k, m+n-2);
vector<long long> cur(total, LLONG_MAX);
auto dijkstra = [&](vector<long long>& d) {
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
for (int i = 0; i < total; i++)
if (d[i] != LLONG_MAX) pq.push({d[i], i});
while (!pq.empty()) {
auto [dd, cell] = pq.top(); pq.pop();
if (dd > d[cell]) continue;
int r = cell/n, c = cell%n;
if (r+1 < m) {
int nc = (r+1)*n+c;
long long nd = dd + grid[r+1][c];
if (nd < d[nc]) { d[nc] = nd; pq.push({nd, nc}); }
}
if (c+1 < n) {
int nc = r*n+c+1;
long long nd = dd + grid[r][c+1];
if (nd < d[nc]) { d[nc] = nd; pq.push({nd, nc}); }
}
}
};
cur[0] = 0;
dijkstra(cur);
vector<int> order(total);
iota(order.begin(), order.end(), 0);
sort(order.begin(), order.end(), [&](int a, int b){
return grid[a/n][a%n] < grid[b/n][b%n];
});
for (int t = 0; t < kk; t++) {
vector<long long> next(total, LLONG_MAX);
long long suffMin = LLONG_MAX;
int idx = total-1;
while (idx >= 0) {
int val = grid[order[idx]/n][order[idx]%n];
int start = idx;
long long groupMin = LLONG_MAX;
while (idx >= 0 && grid[order[idx]/n][order[idx]%n] == val) {
if (cur[order[idx]] != LLONG_MAX)
groupMin = min(groupMin, cur[order[idx]]);
idx--;
}
long long tmin = suffMin;
if (groupMin != LLONG_MAX) tmin = (tmin == LLONG_MAX) ? groupMin : min(tmin, groupMin);
for (int j = start; j > idx; j--) {
if (tmin != LLONG_MAX) next[order[j]] = tmin;
}
suffMin = tmin;
}
dijkstra(next);
for (int i = 0; i < total; i++)
cur[i] = min(cur[i], next[i]);
}
return cur[total-1] == LLONG_MAX ? -1 : (int)cur[total-1];
}
};
