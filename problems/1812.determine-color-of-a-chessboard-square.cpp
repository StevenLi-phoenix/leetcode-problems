// @leetcode id=1812 questionId=1920 slug=determine-color-of-a-chessboard-square lang=cpp site=leetcode.com title="Determine Color of a Chessboard Square"
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int col = coordinates[0] - 'a';
        int row = coordinates[1] - '1';
        return (col + row) % 2 == 1;
    }
};
