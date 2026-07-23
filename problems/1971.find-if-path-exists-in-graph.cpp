// @leetcode id=1971 questionId=2121 slug=find-if-path-exists-in-graph lang=cpp site=leetcode.com title="Find if Path Exists in Graph"
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto& e : edges) {
            unite(e[0], e[1]);
        }

        return find(source) == find(destination);
    }
};
