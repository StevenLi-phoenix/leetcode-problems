// @leetcode id=2976 questionId=3235 slug=minimum-cost-to-convert-string-i lang=cpp site=leetcode.com title="Minimum Cost to Convert String I"
class Solution {
public:
long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
const long long INF = 1e18;
vector<vector<long long>> dist(26, vector<long long>(26, INF));
for (int i = 0; i < 26; i++) dist[i][i] = 0;
for (int i = 0; i < (int)original.size(); i++) {
int u = original[i]-'a', v = changed[i]-'a';
dist[u][v] = min(dist[u][v], (long long)cost[i]);
}
for (int k = 0; k < 26; k++)
for (int i = 0; i < 26; i++)
for (int j = 0; j < 26; j++)
if (dist[i][k] != INF && dist[k][j] != INF)
dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
long long ans = 0;
for (int i = 0; i < (int)source.size(); i++) {
int u = source[i]-'a', v = target[i]-'a';
if (u == v) continue;
if (dist[u][v] == INF) return -1;
ans += dist[u][v];
}
return ans;
}
};
