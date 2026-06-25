// @leetcode id=329 questionId=329 slug=longest-increasing-path-in-a-matrix lang=cpp site=leetcode.com title="Longest Increasing Path in a Matrix"
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int res = 0;
        
        function<int(int, int)> dfs = [&](int r, int c) -> int {
            if (memo[r][c]) return memo[r][c];
            int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
            int best = 1;
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]) {
                    best = max(best, 1 + dfs(nr, nc));
                }
            }
            return memo[r][c] = best;
        };
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res = max(res, dfs(i, j));
        
        return res;
    }
};
