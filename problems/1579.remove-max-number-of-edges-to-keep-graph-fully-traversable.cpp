// @leetcode id=1579 questionId=1701 slug=remove-max-number-of-edges-to-keep-graph-fully-traversable lang=cpp site=leetcode.com title="Remove Max Number of Edges to Keep Graph Fully Traversable"
class Solution {
public:
    struct DSU {
        vector<int> parent, rank_;
        int components;
        DSU(int n) : parent(n+1), rank_(n+1, 0), components(n) {
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        bool unite(int x, int y) {
            x = find(x); y = find(y);
            if (x == y) return false;
            if (rank_[x] < rank_[y]) swap(x, y);
            parent[y] = x;
            if (rank_[x] == rank_[y]) rank_[x]++;
            components--;
            return true;
        }
        bool connected() { return components == 1; }
    };
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n), bob(n);
        int removed = 0;
        
        // First process type 3 edges (shared by both)
        for (auto& e : edges) {
            if (e[0] == 3) {
                bool a = alice.unite(e[1], e[2]);
                bool b = bob.unite(e[1], e[2]);
                if (!a && !b) removed++;
            }
        }
        
        // Then process type 1 (Alice) and type 2 (Bob)
        for (auto& e : edges) {
            if (e[0] == 1) {
                if (!alice.unite(e[1], e[2])) removed++;
            } else if (e[0] == 2) {
                if (!bob.unite(e[1], e[2])) removed++;
            }
        }
        
        if (!alice.connected() || !bob.connected()) return -1;
        return removed;
    }
};
