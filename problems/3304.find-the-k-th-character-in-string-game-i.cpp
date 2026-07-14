// @leetcode id=3304 questionId=3600 slug=find-the-k-th-character-in-string-game-i lang=cpp site=leetcode.com title="Find the K-th Character in String Game I"
class Solution {
public:
    char kthCharacter(int k) {
        int shifts = __builtin_popcount(k - 1);
        return 'a' + (shifts % 26);
    }
};
