// @leetcode id=2039 questionId=2151 slug=the-time-when-the-network-becomes-idle lang=cpp site=leetcode.com title="The Time When the Network Becomes Idle"
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dist(n, -1);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] != -1) continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }

        int answer = 0;
        for (int i = 1; i < n; i++) {
            long long rt = 2LL * dist[i];
            long long lastSend = ((rt - 1) / patience[i]) * patience[i];
            answer = max(answer, (int)(lastSend + rt + 1));
        }
        return answer;
    }
};
