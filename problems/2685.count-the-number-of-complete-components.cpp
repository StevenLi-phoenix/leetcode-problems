// @leetcode id=2685 questionId=2793 slug=count-the-number-of-complete-components lang=cpp site=leetcode.com title="Count the Number of Complete Components"
class Solution {
public:
    vector<int> parent, sz;
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto& e : edges) unite(e[0], e[1]);
        vector<long long> nodeCount(n, 0), edgeCount(n, 0);
        for (int i = 0; i < n; i++) nodeCount[find(i)]++;
        for (auto& e : edges) edgeCount[find(e[0])]++;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                long long m = nodeCount[i];
                if (edgeCount[i] == m * (m - 1) / 2) ans++;
            }
        }
        return ans;
    }
};
