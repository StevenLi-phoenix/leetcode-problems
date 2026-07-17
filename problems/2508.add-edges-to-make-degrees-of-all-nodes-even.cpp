// @leetcode id=2508 questionId=2596 slug=add-edges-to-make-degrees-of-all-nodes-even lang=cpp site=leetcode.com title="Add Edges to Make Degrees of All Nodes Even"
class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n + 1);
        vector<int> degree(n + 1, 0);

        for (auto& e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (degree[i] % 2 == 1) odd.push_back(i);
        }

        if (odd.empty()) return true;

        if (odd.size() == 2) {
            int a = odd[0], b = odd[1];
            if (!adj[a].count(b)) return true;
            for (int c = 1; c <= n; c++) {
                if (c == a || c == b) continue;
                if (!adj[a].count(c) && !adj[b].count(c)) return true;
            }
            return false;
        }

        if (odd.size() == 4) {
            int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
            vector<array<int,4>> pairings = {{a,b,c,d}, {a,c,b,d}, {a,d,b,c}};
            for (auto& p : pairings) {
                if (!adj[p[0]].count(p[1]) && !adj[p[2]].count(p[3])) return true;
            }
            return false;
        }

        return false;
    }
};
