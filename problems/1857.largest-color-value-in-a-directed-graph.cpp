// @leetcode id=1857 questionId=1986 slug=largest-color-value-in-a-directed-graph lang=cpp site=leetcode.com title="Largest Color Value in a Directed Graph"
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        vector<array<int, 26>> dp(n);
        for (auto& row : dp) row.fill(0);

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        int visited = 0;
        int ans = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited++;
            dp[u][colors[u] - 'a']++;
            ans = max(ans, dp[u][colors[u] - 'a']);
            for (int v : adj[u]) {
                for (int c = 0; c < 26; c++) {
                    dp[v][c] = max(dp[v][c], dp[u][c]);
                }
                if (--indeg[v] == 0) q.push(v);
            }
        }

        return visited == n ? ans : -1;
    }
};
