// @leetcode id=1351 questionId=1476 slug=count-negative-numbers-in-a-sorted-matrix lang=cpp site=leetcode.com title="Count Negative Numbers in a Sorted Matrix"
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        int r = 0, c = n - 1;
        int ans = 0;

        while (r < m && c >= 0) {
            if (grid[r][c] < 0) {
                ans += (m - r);   // all rows from r..m-1 in this column are negative
                --c;              // move left
            } else {
                ++r;              // move down
            }
        }
        return ans;
    }
};
