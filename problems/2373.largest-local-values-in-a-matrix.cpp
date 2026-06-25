// @leetcode id=2373 questionId=2454 slug=largest-local-values-in-a-matrix lang=cpp site=leetcode.com title="Largest Local Values in a Matrix"
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2));
        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < n-2; j++) {
                int mx = 0;
                for (int di = 0; di <= 2; di++)
                    for (int dj = 0; dj <= 2; dj++)
                        mx = max(mx, grid[i+di][j+dj]);
                res[i][j] = mx;
            }
        }
        return res;
    }
};
