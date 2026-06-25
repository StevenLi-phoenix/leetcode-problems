// @leetcode id=3417 questionId=3708 slug=zigzag-grid-traversal-with-skip lang=cpp site=leetcode.com title="Zigzag Grid Traversal With Skip"
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> result;
        bool pick = true; // pick every other cell
        for (int i = 0; i < m; i++) {
            if (i % 2 == 0) {
                // left to right
                for (int j = 0; j < n; j++) {
                    if (pick) result.push_back(grid[i][j]);
                    pick = !pick;
                }
            } else {
                // right to left
                for (int j = n - 1; j >= 0; j--) {
                    if (pick) result.push_back(grid[i][j]);
                    pick = !pick;
                }
            }
        }
        return result;
    }
};
