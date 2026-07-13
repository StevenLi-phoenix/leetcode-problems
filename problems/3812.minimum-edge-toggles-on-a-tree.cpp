// @leetcode id=3812 questionId=4181 slug=minimum-edge-toggles-on-a-tree lang=cpp site=leetcode.com title="Minimum Edge Toggles on a Tree"
class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        // Peel leaves inward (iterative, like Kahn's algorithm): a leaf's
        // single remaining edge is forced to be toggled iff the leaf still
        // needs a parity flip; that choice is always safe since the leaf
        // has no other edge to fix it later. Toggling propagates the
        // parity requirement to the neighbor.
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < (int)edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }

        vector<int> degree(n);
        for (int i = 0; i < n; i++) degree[i] = adj[i].size();

        vector<char> diff(n);
        for (int i = 0; i < n; i++) diff[i] = (start[i] != target[i]) ? 1 : 0;

        vector<char> edgeUsed(edges.size(), 0);
        vector<char> edgeRemoved(edges.size(), 0);

        queue<int> q;
        for (int i = 0; i < n; i++) if (degree[i] == 1) q.push(i);

        int remainingRoot = -1;
        vector<char> done(n, 0);
        int processedCount = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (done[u]) continue;
            done[u] = 1;
            processedCount++;

            if (processedCount == n) {
                remainingRoot = u;
                break;
            }

            // find the unique alive edge from u
            int v = -1, idx = -1;
            for (auto& [nb, ei] : adj[u]) {
                if (!edgeRemoved[ei]) {
                    v = nb;
                    idx = ei;
                    break;
                }
            }
            edgeRemoved[idx] = 1;
            degree[v]--;

            if (diff[u] == 1) {
                edgeUsed[idx] = 1;
                diff[v] ^= 1;
            }

            if (degree[v] == 1 && !done[v]) q.push(v);
            else if (degree[v] == 0 && !done[v]) q.push(v);
        }

        if (remainingRoot != -1 && diff[remainingRoot] != 0) return {-1};

        vector<int> result;
        for (int i = 0; i < (int)edges.size(); i++) if (edgeUsed[i]) result.push_back(i);
        return result;
    }
};
