// @leetcode id=3274 questionId=3553 slug=check-if-two-chessboard-squares-have-the-same-color lang=cpp site=leetcode.com title="Check if Two Chessboard Squares Have the Same Color"
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int p1 = (coordinate1[0] - 'a' + coordinate1[1] - '0') % 2;
        int p2 = (coordinate2[0] - 'a' + coordinate2[1] - '0') % 2;
        return p1 == p2;
    }
};
