// @leetcode id=289 questionId=289 slug=game-of-life lang=cpp site=leetcode.com title="Game of Life"
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && (board[ni][nj] & 1)) live++;
                    }
                }
                if ((board[i][j] & 1) && (live == 2 || live == 3)) board[i][j] |= 2;
                if (!(board[i][j] & 1) && live == 3) board[i][j] |= 2;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};
