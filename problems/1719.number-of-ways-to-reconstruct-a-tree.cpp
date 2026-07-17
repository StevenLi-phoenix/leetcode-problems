// @leetcode id=1719 questionId=1820 slug=number-of-ways-to-reconstruct-a-tree lang=cpp site=leetcode.com title="Number Of Ways To Reconstruct A Tree"
class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto& p : pairs) {
            adj[p[0]].insert(p[1]);
            adj[p[1]].insert(p[0]);
        }

        vector<int> nodes;
        for (auto& [k, v] : adj) nodes.push_back(k);
        int n = nodes.size();

        sort(nodes.begin(), nodes.end(), [&](int a, int b) {
            return adj[a].size() > adj[b].size();
        });

        unordered_map<int,int> parent;
        int rootCount = 0;
        bool multiple = false;

        for (int u : nodes) {
            if ((int)adj[u].size() == n - 1) {
                rootCount++;
                continue;
            }

            int bestParent = -1;
            int bestDeg = INT_MAX;
            for (int v : adj[u]) {
                int dv = adj[v].size();
                if (dv >= (int)adj[u].size() && dv < bestDeg) {
                    bestDeg = dv;
                    bestParent = v;
                }
            }

            if (bestParent == -1) return 0;

            // validity check: adj[u] \ {bestParent} must be subset of adj[bestParent]
            for (int v : adj[u]) {
                if (v == bestParent) continue;
                if (!adj[bestParent].count(v)) return 0;
            }

            if ((int)adj[bestParent].size() == (int)adj[u].size()) multiple = true;

            parent[u] = bestParent;
        }

        if (rootCount == 0) return 0;
        if (rootCount > 1) multiple = true;

        return multiple ? 2 : 1;
    }
};
