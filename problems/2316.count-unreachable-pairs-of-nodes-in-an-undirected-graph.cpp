// @leetcode id=2316 questionId=2403 slug=count-unreachable-pairs-of-nodes-in-an-undirected-graph lang=cpp site=leetcode.com title="Count Unreachable Pairs of Nodes in an Undirected Graph"
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        // Union-Find
        vector<int> parent(n), rank_(n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };
        
        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return;
            if (rank_[a] < rank_[b]) swap(a, b);
            parent[b] = a;
            if (rank_[a] == rank_[b]) rank_[a]++;
        };
        
        for (auto& e : edges) unite(e[0], e[1]);
        
        // Count component sizes
        unordered_map<int,long long> sz;
        for (int i = 0; i < n; i++) sz[find(i)]++;
        
        long long ans = (long long)n * (n - 1) / 2;
        for (auto& [root, s] : sz) ans -= s * (s - 1) / 2;
        return ans;
    }
};
