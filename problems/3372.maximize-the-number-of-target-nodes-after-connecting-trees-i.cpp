// @leetcode id=3372 questionId=3633 slug=maximize-the-number-of-target-nodes-after-connecting-trees-i lang=cpp site=leetcode.com title="Maximize the Number of Target Nodes After Connecting Trees I"
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        vector<int> count1(n);
        for (int i = 0; i < n; i++) count1[i] = countWithin(adj1, i, k);

        int best2 = 0;
        if (k - 1 >= 0) {
            for (int j = 0; j < m; j++) best2 = max(best2, countWithin(adj2, j, k - 1));
        }

        vector<int> answer(n);
        for (int i = 0; i < n; i++) answer[i] = count1[i] + best2;
        return answer;
    }

private:
    int countWithin(vector<vector<int>>& adj, int src, int limit) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (dist[u] > limit) continue;
            cnt++;
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return cnt;
    }
};
