// @leetcode id=2713 questionId=2818 slug=maximum-strictly-increasing-cells-in-a-matrix lang=cpp site=leetcode.com title="Maximum Strictly Increasing Cells in a Matrix"
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<pair<int,int>>> groups;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                groups[mat[i][j]].push_back({i, j});
            }
        }

        vector<int> rowBest(m, 0), colBest(n, 0);
        int answer = 0;

        for (auto& [val, cells] : groups) {
            vector<int> dp(cells.size());
            for (size_t k = 0; k < cells.size(); k++) {
                int r = cells[k].first, c = cells[k].second;
                dp[k] = 1 + max(rowBest[r], colBest[c]);
                answer = max(answer, dp[k]);
            }
            for (size_t k = 0; k < cells.size(); k++) {
                int r = cells[k].first, c = cells[k].second;
                rowBest[r] = max(rowBest[r], dp[k]);
                colBest[c] = max(colBest[c], dp[k]);
            }
        }

        return answer;
    }
};
