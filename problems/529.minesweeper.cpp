// @leetcode id=529 questionId=529 slug=minesweeper lang=cpp site=leetcode.com title="Minesweeper"
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int r = click[0], c = click[1];

        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};

        queue<pair<int,int>> q;
        q.push({r, c});
        board[r][c] = 'B'; // placeholder, will be overwritten with count if needed

        while (!q.empty()) {
            auto [cr, cc] = q.front(); q.pop();
            int mineCount = 0;
            vector<pair<int,int>> neighbors;
            for (int d = 0; d < 8; d++) {
                int nr = cr + dr[d], nc = cc + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (board[nr][nc] == 'M') mineCount++;
                else neighbors.push_back({nr, nc});
            }
            if (mineCount > 0) {
                board[cr][cc] = '0' + mineCount;
            } else {
                board[cr][cc] = 'B';
                for (auto& [nr, nc] : neighbors) {
                    if (board[nr][nc] == 'E') {
                        board[nr][nc] = 'B'; // mark visited to avoid re-queueing
                        q.push({nr, nc});
                    }
                }
            }
        }
        return board;
    }
};
