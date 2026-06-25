// @leetcode id=1559 questionId=1663 slug=detect-cycles-in-2d-grid lang=cpp site=leetcode.com title="Detect Cycles in 2D Grid"
class Solution {
    public:
    vector<int> parent, rank_;
    int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
    }
    bool unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (rank_[a] < rank_[b]) swap(a, b);
    parent[b] = a;
    if (rank_[a] == rank_[b]) rank_[a]++;
    return true;
    }
    bool containsCycle(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    parent.resize(m * n);
    rank_.resize(m * n, 0);
    for (int i = 0; i < m * n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
    if (i + 1 < m && grid[i+1][j] == grid[i][j]) {
    if (!unite(i*n+j, (i+1)*n+j)) return true;
    }
    if (j + 1 < n && grid[i][j+1] == grid[i][j]) {
    if (!unite(i*n+j, i*n+j+1)) return true;
    }
    }
    }
    return false;
    }
    };
