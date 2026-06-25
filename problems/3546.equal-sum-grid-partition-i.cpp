// @leetcode id=3546 questionId=3849 slug=equal-sum-grid-partition-i lang=cpp site=leetcode.com title="Equal Sum Grid Partition I"
class Solution {
    public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    long long total = 0;
    for (auto& row : grid) for (int v : row) total += v;
    long long sum = 0;
    for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < n; j++) sum += grid[i][j];
    if (sum * 2 == total) return true;
    }
    sum = 0;
    for (int j = 0; j < n - 1; j++) {
    for (int i = 0; i < m; i++) sum += grid[i][j];
    if (sum * 2 == total) return true;
    }
    return false;
    }
    };
