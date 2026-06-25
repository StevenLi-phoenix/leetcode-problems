// @leetcode id=2132 questionId=2200 slug=stamping-the-grid lang=cpp site=leetcode.com title="Stamping the Grid"
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        int H = stampHeight, W = stampWidth;
        
        // Compute 2D prefix sum of grid
        // prefix[i][j] = sum of grid[0..i-1][0..j-1]
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        // For each valid stamp position (i,j) [top-left corner, 1-indexed]
        // Check if rectangle sum = 0 (no occupied cells)
        // If so, use 2D difference array to mark coverage
        vector<vector<int>> diff(m + 2, vector<int>(n + 2, 0));
        
        auto rectSum = [&](int r1, int c1, int r2, int c2) {
            return prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
        };
        
        for (int i = 1; i + H - 1 <= m; i++) {
            for (int j = 1; j + W - 1 <= n; j++) {
                int r2 = i + H - 1, c2 = j + W - 1;
                if (rectSum(i, j, r2, c2) == 0) {
                    // Stamp can be placed here
                    diff[i][j]++;
                    diff[i][c2 + 1]--;
                    diff[r2 + 1][j]--;
                    diff[r2 + 1][c2 + 1]++;
                }
            }
        }
        
        // Convert diff to coverage count using prefix sum
        // Check if every empty cell has coverage >= 1
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                diff[i][j] += diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
                if (grid[i-1][j-1] == 0 && diff[i][j] == 0) {
                    return false; // Empty cell not covered
                }
            }
        }
        
        return true;
    }
};
