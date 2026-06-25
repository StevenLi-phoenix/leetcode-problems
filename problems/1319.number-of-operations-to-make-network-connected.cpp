// @leetcode id=1319 questionId=1442 slug=number-of-operations-to-make-network-connected lang=cpp site=leetcode.com title="Number of Operations to Make Network Connected"
class Solution {
public:
    vector<int> parent, rank_;
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        if (rank_[ra] < rank_[rb]) swap(ra, rb);
        parent[rb] = ra;
        if (rank_[ra] == rank_[rb]) rank_[ra]++;
        return true;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if ((int)connections.size() < n - 1) return -1;
        parent.resize(n);
        rank_.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        int components = n;
        for (auto& c : connections) {
            if (unite(c[0], c[1]))
                components--;
        }
        return components - 1;
    }
};
