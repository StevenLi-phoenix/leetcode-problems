// @leetcode id=1275 questionId=1400 slug=find-winner-on-a-tic-tac-toe-game lang=cpp site=leetcode.com title="Find Winner on a Tic Tac Toe Game"
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int rows[2][3] = {}, cols[2][3] = {}, diag[2] = {}, anti[2] = {};
        for (int i = 0; i < (int)moves.size(); i++) {
            int player = i % 2;
            int r = moves[i][0], c = moves[i][1];
            rows[player][r]++;
            cols[player][c]++;
            if (r == c) diag[player]++;
            if (r + c == 2) anti[player]++;

            if (rows[player][r] == 3 || cols[player][c] == 3 ||
                diag[player] == 3 || anti[player] == 3) {
                return player == 0 ? "A" : "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
