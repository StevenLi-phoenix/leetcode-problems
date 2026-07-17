// @leetcode id=2065 questionId=2189 slug=maximum-path-quality-of-a-graph lang=cpp site=leetcode.com title="Maximum Path Quality of a Graph"
class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<bool> visited;
    int best = 0;

    void dfs(int node, int timeLeft, int quality, vector<int>& values) {
        if (node == 0) best = max(best, quality);

        for (auto& [next, cost] : adj[node]) {
            if (cost > timeLeft) continue;

            if (visited[next]) {
                dfs(next, timeLeft - cost, quality, values);
            } else {
                visited[next] = true;
                dfs(next, timeLeft - cost, quality + values[next], values);
                visited[next] = false;
            }
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        visited.assign(n, false);
        visited[0] = true;
        dfs(0, maxTime, values[0], values);

        return best;
    }
};
