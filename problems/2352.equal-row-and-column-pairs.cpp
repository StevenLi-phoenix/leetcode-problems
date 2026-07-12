// @leetcode id=2352 questionId=2428 slug=equal-row-and-column-pairs lang=cpp site=leetcode.com title="Equal Row and Column Pairs"
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rowCount;
        for (auto& row : grid) rowCount[row]++;

        int ans = 0;
        for (int c = 0; c < n; c++) {
            vector<int> col(n);
            for (int r = 0; r < n; r++) col[r] = grid[r][c];
            auto it = rowCount.find(col);
            if (it != rowCount.end()) ans += it->second;
        }
        return ans;
    }
};
