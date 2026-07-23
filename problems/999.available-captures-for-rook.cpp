// @leetcode id=999 questionId=1041 slug=available-captures-for-rook lang=cpp site=leetcode.com title="Available Captures for Rook"
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rr = -1, rc = -1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') { rr = i; rc = j; }
            }
        }

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int count = 0;
        for (auto& d : dirs) {
            int i = rr + d[0], j = rc + d[1];
            while (i >= 0 && i < 8 && j >= 0 && j < 8) {
                if (board[i][j] == 'B') break;
                if (board[i][j] == 'p') { count++; break; }
                i += d[0];
                j += d[1];
            }
        }
        return count;
    }
};
