// @leetcode id=1958 questionId=2080 slug=check-if-move-is-legal lang=cpp site=leetcode.com title="Check if Move is Legal"
class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        // Place the piece
        board[rMove][cMove] = color;
        char opposite = (color == 'W') ? 'B' : 'W';
        
        int dirs[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        for (auto& d : dirs) {
            int r = rMove + d[0];
            int c = cMove + d[1];
            int len = 1;
            
            // Must have at least one opposite color cell first
            while (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == opposite) {
                r += d[0];
                c += d[1];
                len++;
            }
            
            // Check: len >= 2 (at least one opposite in middle), 
            // and next cell is same color (not free, not out of bounds)
            if (len >= 2 && r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == color) {
                return true;
            }
        }
        return false;
    }
};
