// @leetcode id=807 questionId=825 slug=max-increase-to-keep-city-skyline lang=cpp site=leetcode.com title="Max Increase to Keep City Skyline"
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rowMax(n, 0), colMax(n, 0);

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                rowMax[r] = max(rowMax[r], grid[r][c]);
                colMax[c] = max(colMax[c], grid[r][c]);
            }
        }

        int total = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                total += min(rowMax[r], colMax[c]) - grid[r][c];
            }
        }
        return total;
    }
};
