// @leetcode id=1489 questionId=1613 slug=find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree lang=cpp site=leetcode.com title="Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree"
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }

    // returns MST weight given a forced-include edge index and a forced-exclude edge index (-1 for none)
    int mstWeight(int n, vector<vector<int>>& edges, vector<int>& order, int forceInclude, int forceExclude) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        int weight = 0, count = 0;

        if (forceInclude != -1) {
            auto& e = edges[forceInclude];
            int ra = find(e[0]), rb = find(e[1]);
            if (ra == rb) return INT_MAX; // shouldn't happen for valid MST edge
            parent[ra] = rb;
            weight += e[2];
            count++;
        }

        for (int idx : order) {
            if (idx == forceExclude || idx == forceInclude) continue;
            auto& e = edges[idx];
            int ra = find(e[0]), rb = find(e[1]);
            if (ra != rb) {
                parent[ra] = rb;
                weight += e[2];
                count++;
            }
        }

        if (count != n - 1) return INT_MAX;
        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> order(m);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return edges[a][2] < edges[b][2];
        });

        int baseWeight = mstWeight(n, edges, order, -1, -1);

        vector<int> critical, pseudo;

        for (int i = 0; i < m; i++) {
            int withoutWeight = mstWeight(n, edges, order, -1, i);
            if (withoutWeight > baseWeight) {
                critical.push_back(i);
                continue;
            }

            int withWeight = mstWeight(n, edges, order, i, -1);
            if (withWeight == baseWeight) {
                pseudo.push_back(i);
            }
        }

        return {critical, pseudo};
    }
};
