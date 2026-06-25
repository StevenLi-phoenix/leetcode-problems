// @leetcode id=2596 questionId=2662 slug=check-knight-tour-configuration lang=cpp site=leetcode.com title="Check Knight Tour Configuration"
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] != 0) return false;

        vector<vector<int>> pos(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }

        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        for (int move = 0; move < n * n - 1; move++) {
            int x1 = pos[move][0], y1 = pos[move][1];
            int x2 = pos[move + 1][0], y2 = pos[move + 1][1];

            bool valid = false;
            for (int k = 0; k < 8; k++) {
                if (x1 + dx[k] == x2 && y1 + dy[k] == y2) {
                    valid = true;
                    break;
                }
            }

            if (!valid) return false;
        }

        return true;
    }
};
