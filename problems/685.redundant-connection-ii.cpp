// @leetcode id=685 questionId=685 slug=redundant-connection-ii lang=cpp site=leetcode.com title="Redundant Connection II"
class Solution {
public:
    vector<int> parent_;

    int find(int x) {
        while (parent_[x] != x) {
            parent_[x] = parent_[parent_[x]];
            x = parent_[x];
        }
        return x;
    }

    // Tries to build a tree using all edges except `skipIdx`. Returns the
    // first edge that would create a cycle, or empty if none does.
    vector<int> unionFindSkip(vector<vector<int>>& edges, int n, int skipIdx) {
        parent_.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) parent_[i] = i;
        for (int i = 0; i < (int)edges.size(); i++) {
            if (i == skipIdx) continue;
            int u = edges[i][0], v = edges[i][1];
            int ru = find(u), rv = find(v);
            if (ru == rv) return edges[i];
            parent_[rv] = ru;
        }
        return {};
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parentOf(n + 1, 0);
        int edge1Idx = -1, edge2Idx = -1;

        for (int i = 0; i < n; i++) {
            int v = edges[i][1];
            if (parentOf[v] != 0) {
                edge1Idx = parentOf[v] - 1; // index of the first edge into v
                edge2Idx = i;
                break;
            }
            parentOf[v] = i + 1;
        }

        if (edge2Idx == -1) {
            // No node has two parents: the redundant edge is whichever
            // creates a cycle.
            return unionFindSkip(edges, n, -1);
        }

        // A node has two parents (edges[edge1Idx] and edges[edge2Idx]).
        // Try removing the later one first; if the rest forms a valid tree,
        // that's the answer. Otherwise the cycle must involve edge1Idx.
        vector<int> cycleEdge = unionFindSkip(edges, n, edge2Idx);
        if (cycleEdge.empty()) return edges[edge2Idx];
        return edges[edge1Idx];
    }
};
