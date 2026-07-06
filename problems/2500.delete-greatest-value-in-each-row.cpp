// @leetcode id=2500 questionId=2585 slug=delete-greatest-value-in-each-row lang=cpp site=leetcode.com title="Delete Greatest Value in Each Row"
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto& row : grid) sort(row.begin(), row.end());

        int n = grid[0].size();
        int ans = 0;
        for (int col = 0; col < n; ++col) {
            int colMax = 0;
            for (auto& row : grid) colMax = max(colMax, row[col]);
            ans += colMax;
        }
        return ans;
    }
};
