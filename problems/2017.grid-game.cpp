// @leetcode id=2017 questionId=2145 slug=grid-game lang=cpp site=leetcode.com title="Grid Game"
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long topSum = 0;
        for (int c = 0; c < n; c++) topSum += grid[0][c];

        long long topPrefix = 0, bottomPrefix = 0;
        long long best = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            topPrefix += grid[0][i];
            long long topRemaining = topSum - topPrefix;
            long long bottomBefore = bottomPrefix;
            best = min(best, max(topRemaining, bottomBefore));
            bottomPrefix += grid[1][i];
        }
        return best;
    }
};
