// @leetcode id=2639 questionId=2675 slug=find-the-width-of-columns-of-a-grid lang=cpp site=leetcode.com title="Find the Width of Columns of a Grid"
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int cols = grid[0].size();
        vector<int> result(cols, 0);

        for (int j = 0; j < cols; j++) {
            int maxWidth = 0;
            for (int i = 0; i < grid.size(); i++) {
                string s = to_string(grid[i][j]);
                maxWidth = max(maxWidth, (int)s.length());
            }
            result[j] = maxWidth;
        }

        return result;
    }
};
