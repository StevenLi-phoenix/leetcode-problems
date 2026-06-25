// @leetcode id=861 questionId=891 slug=score-after-flipping-matrix lang=cpp site=leetcode.com title="Score After Flipping Matrix"
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Step 1: Make all first column elements 1 by flipping rows
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }
        
        // Step 2: For each column (starting from 1), maximize 1s
        for (int j = 1; j < n; j++) {
            int ones = 0;
            for (int i = 0; i < m; i++) {
                ones += grid[i][j];
            }
            if (ones < m - ones) {
                // Flip this column
                for (int i = 0; i < m; i++) {
                    grid[i][j] ^= 1;
                }
            }
        }
        
        // Calculate score
        int score = 0;
        for (int i = 0; i < m; i++) {
            int val = 0;
            for (int j = 0; j < n; j++) {
                val = val * 2 + grid[i][j];
            }
            score += val;
        }
        return score;
    }
};
