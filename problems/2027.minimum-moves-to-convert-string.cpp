// @leetcode id=2027 questionId=2154 slug=minimum-moves-to-convert-string lang=cpp site=leetcode.com title="Minimum Moves to Convert String"
class Solution {
public:
    int minimumMoves(string s) {
        int moves = 0;
        int i = 0;
        int n = s.size();
        while (i < n) {
            if (s[i] == 'X') {
                moves++;
                i += 3;
            } else {
                i++;
            }
        }
        return moves;
    }
};
