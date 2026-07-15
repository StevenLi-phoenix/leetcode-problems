// @leetcode id=3537 questionId=3822 slug=fill-a-special-grid lang=cpp site=leetcode.com title="Fill a Special Grid"
class Solution {
public:
    void fill(vector<vector<int>>& grid, int r, int c, int n, long long start) {
        if (n == 0) {
            grid[r][c] = start;
            return;
        }
        int half = 1 << (n - 1);
        long long quadSize = (long long)half * half;
        fill(grid, r, c + half, n - 1, start);
        fill(grid, r + half, c + half, n - 1, start + quadSize);
        fill(grid, r + half, c, n - 1, start + 2 * quadSize);
        fill(grid, r, c, n - 1, start + 3 * quadSize);
    }

    vector<vector<int>> specialGrid(int n) {
        int size = 1 << n;
        vector<vector<int>> grid(size, vector<int>(size));
        fill(grid, 0, 0, n, 0);
        return grid;
    }
};
