// @leetcode id=1222 questionId=1342 slug=queens-that-can-attack-the-king lang=cpp site=leetcode.com title="Queens That Can Attack the King"
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> board(8, vector<int>(8, 0));
        for (auto& q : queens) board[q[0]][q[1]] = 1;

        vector<vector<int>> result;
        int dirs[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        for (auto& d : dirs) {
            int x = king[0] + d[0], y = king[1] + d[1];
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (board[x][y] == 1) {
                    result.push_back({x, y});
                    break;
                }
                x += d[0];
                y += d[1];
            }
        }
        return result;
    }
};
