// @leetcode id=292 questionId=292 slug=nim-game lang=cpp site=leetcode.com title="Nim Game"
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
