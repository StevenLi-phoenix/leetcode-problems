// @leetcode id=1289 questionId=1224 slug=minimum-falling-path-sum-ii lang=cpp site=leetcode.com title="Minimum Falling Path Sum II"
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> prev = grid[0];

        for (int r = 1; r < n; r++) {
            int min1 = INT_MAX, min1Idx = -1, min2 = INT_MAX;
            for (int c = 0; c < n; c++) {
                if (prev[c] < min1) {
                    min2 = min1;
                    min1 = prev[c];
                    min1Idx = c;
                } else if (prev[c] < min2) {
                    min2 = prev[c];
                }
            }

            vector<int> cur(n);
            for (int c = 0; c < n; c++) {
                int best = (c == min1Idx) ? min2 : min1;
                cur[c] = grid[r][c] + best;
            }
            prev = cur;
        }

        return *min_element(prev.begin(), prev.end());
    }
};
