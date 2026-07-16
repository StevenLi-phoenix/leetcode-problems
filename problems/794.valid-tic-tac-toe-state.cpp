// @leetcode id=794 questionId=810 slug=valid-tic-tac-toe-state lang=cpp site=leetcode.com title="Valid Tic-Tac-Toe State"
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        for (auto& row : board) {
            for (char c : row) {
                if (c == 'X') xCount++;
                else if (c == 'O') oCount++;
            }
        }
        if (!(xCount == oCount || xCount == oCount + 1)) return false;

        auto wins = [&](char c) {
            for (int i = 0; i < 3; i++) {
                if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
                if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
            }
            if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
            if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
            return false;
        };

        bool xWins = wins('X');
        bool oWins = wins('O');

        if (xWins && oWins) return false;
        if (xWins && xCount != oCount + 1) return false;
        if (oWins && xCount != oCount) return false;

        return true;
    }
};
