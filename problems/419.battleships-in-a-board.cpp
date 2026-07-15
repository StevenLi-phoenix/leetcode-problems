// @leetcode id=419 questionId=419 slug=battleships-in-a-board lang=cpp site=leetcode.com title="Battleships in a Board"
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int count = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] != 'X') continue;
                if (r > 0 && board[r - 1][c] == 'X') continue;
                if (c > 0 && board[r][c - 1] == 'X') continue;
                count++;
            }
        }
        return count;
    }
};
