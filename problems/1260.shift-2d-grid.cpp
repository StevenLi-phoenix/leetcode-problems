// @leetcode id=1260 questionId=1386 slug=shift-2d-grid lang=cpp site=leetcode.com title="Shift 2D Grid"
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;
        k %= total;
        
        // Flatten
        vector<int> flat;
        for (auto& row : grid)
            for (int x : row)
                flat.push_back(x);
        
        // Rotate right by k: last k elements come first
        vector<int> shifted(flat.end() - k, flat.end());
        shifted.insert(shifted.end(), flat.begin(), flat.end() - k);
        
        // Reshape
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < total; i++)
            res[i / n][i % n] = shifted[i];
        
        return res;
    }
};
