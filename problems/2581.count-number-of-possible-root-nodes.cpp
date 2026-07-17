// @leetcode id=2581 questionId=2652 slug=count-number-of-possible-root-nodes lang=cpp site=leetcode.com title="Count Number of Possible Root Nodes"
class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        set<pair<int,int>> guessSet;
        for (auto& g : guesses) guessSet.insert({g[0], g[1]});

        vector<int> parent(n, -1);
        vector<int> order;
        order.reserve(n);
        vector<bool> visited(n, false);
        vector<int> stack;
        stack.reserve(n);
        stack.push_back(0);
        visited[0] = true;

        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    stack.push_back(v);
                }
            }
        }

        long long baseCount = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1 && guessSet.count({parent[i], i})) baseCount++;
        }

        vector<long long> count(n, 0);
        count[0] = baseCount;

        // reroot using DFS order from root 0
        for (int idx = 1; idx < n; idx++) {
            int u = order[idx];
            int p = parent[u];
            long long c = count[p];
            // when moving root from p to u: edge (p,u) as guess [p,u] loses validity (was correct if root=p had it as parent->child),
            // edge (u,p) as guess gains validity
            if (guessSet.count({p, u})) c--;
            if (guessSet.count({u, p})) c++;
            count[u] = c;
        }

        int answer = 0;
        for (int i = 0; i < n; i++) if (count[i] >= k) answer++;

        return answer;
    }
};
