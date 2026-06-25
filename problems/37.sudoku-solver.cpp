// @leetcode id=37 questionId=37 slug=sudoku-solver lang=cpp site=leetcode.com title="Sudoku Solver"
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0), cols(9, 0), boxes(9, 0);
        vector<pair<int,int>> empty;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int d = board[i][j] - '1';
                    int bit = 1 << d;
                    int box = (i/3)*3 + j/3;
                    rows[i] |= bit;
                    cols[j] |= bit;
                    boxes[box] |= bit;
                } else {
                    empty.push_back({i, j});
                }
            }
        }
        
        function<bool(int)> solve = [&](int idx) -> bool {
            if (idx == (int)empty.size()) return true;
            auto [r, c] = empty[idx];
            int box = (r/3)*3 + c/3;
            int used = rows[r] | cols[c] | boxes[box];
            int avail = (~used) & 0x1FF;
            
            while (avail) {
                int bit = avail & (-avail);
                avail &= avail - 1;
                int d = __builtin_ctz(bit);
                
                board[r][c] = '1' + d;
                rows[r] |= bit;
                cols[c] |= bit;
                boxes[box] |= bit;
                
                if (solve(idx + 1)) return true;
                
                board[r][c] = '.';
                rows[r] ^= bit;
                cols[c] ^= bit;
                boxes[box] ^= bit;
            }
            return false;
        };
        
        solve(0);
    }
};
