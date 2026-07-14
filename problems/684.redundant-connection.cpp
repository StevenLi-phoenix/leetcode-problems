// @leetcode id=684 questionId=684 slug=redundant-connection lang=cpp site=leetcode.com title="Redundant Connection"
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;

        for (auto& e : edges) {
            int ru = find(e[0]), rv = find(e[1]);
            if (ru == rv) return e;
            parent[ru] = rv;
        }
        return {};
    }
};
