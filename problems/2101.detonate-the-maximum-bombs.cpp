// @leetcode id=2101 questionId=2206 slug=detonate-the-maximum-bombs lang=cpp site=leetcode.com title="Detonate the Maximum Bombs"
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; ++i) {
            long long xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                long long dx = xi - bombs[j][0];
                long long dy = yi - bombs[j][1];
                if (dx * dx + dy * dy <= ri * ri) {
                    adj[i].push_back(j);
                }
            }
        }

        int best = 0;
        for (int start = 0; start < n; ++start) {
            vector<bool> visited(n, false);
            visited[start] = true;
            queue<int> q;
            q.push(start);
            int count = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        ++count;
                        q.push(v);
                    }
                }
            }
            best = max(best, count);
        }
        return best;
    }
};
