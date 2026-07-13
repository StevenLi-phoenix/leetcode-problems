// @leetcode id=2858 questionId=3105 slug=minimum-edge-reversals-so-every-node-is-reachable lang=cpp site=leetcode.com title="Minimum Edge Reversals So Every Node Is Reachable"
class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        // adj[u] holds (v, 1) if the original edge is u->v (traversing
        // this way follows the edge, free), or (v, 0) if it's v->u
        // (traversing u->v goes against it, costs a reversal).
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], 1});
            adj[e[1]].push_back({e[0], 0});
        }

        // First pass: compute ans[0] as the total edges traversed against
        // their direction while walking outward from node 0.
        vector<char> visited(n, 0);
        int total = 0;
        visited[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& [v, ok] : adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    if (!ok) total++;
                    q.push(v);
                }
            }
        }

        // Reroot: shifting the root across an edge changes the count by
        // +1 (if that edge originally pointed toward the old root, i.e.
        // was free before) or -1 (if it pointed away, i.e. cost 1 before).
        vector<int> ans(n, 0);
        vector<char> visited2(n, 0);
        ans[0] = total;
        visited2[0] = 1;
        queue<int> q2;
        q2.push(0);
        while (!q2.empty()) {
            int u = q2.front();
            q2.pop();
            for (auto& [v, ok] : adj[u]) {
                if (!visited2[v]) {
                    visited2[v] = 1;
                    ans[v] = ans[u] + (ok ? 1 : -1);
                    q2.push(v);
                }
            }
        }

        return ans;
    }
};
