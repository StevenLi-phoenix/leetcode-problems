// @leetcode id=3242 questionId=3516 slug=design-neighbor-sum-service lang=cpp site=leetcode.com title="Design Neighbor Sum Service"
class NeighborSum {
public:
    vector<vector<int>> g;
    int n;
    unordered_map<int, pair<int, int>> pos;

    NeighborSum(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }
    }

    int adjacentSum(int value) {
        auto [r, c] = pos[value];
        int sum = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) sum += g[nr][nc];
        }
        return sum;
    }

    int diagonalSum(int value) {
        auto [r, c] = pos[value];
        int sum = 0;
        int dirs[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) sum += g[nr][nc];
        }
        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
