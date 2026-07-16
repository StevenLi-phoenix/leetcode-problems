// @leetcode id=1138 questionId=1238 slug=alphabet-board-path lang=cpp site=leetcode.com title="Alphabet Board Path"
class Solution {
public:
    string alphabetBoardPath(string target) {
        string result;
        int curRow = 0, curCol = 0;
        for (char ch : target) {
            int idx = ch - 'a';
            int row = idx / 5, col = idx % 5;
            int dr = row - curRow, dc = col - curCol;

            if (dr < 0) result += string(-dr, 'U');
            if (dc < 0) result += string(-dc, 'L');
            if (dr > 0) result += string(dr, 'D');
            if (dc > 0) result += string(dc, 'R');
            result += '!';

            curRow = row; curCol = col;
        }
        return result;
    }
};
