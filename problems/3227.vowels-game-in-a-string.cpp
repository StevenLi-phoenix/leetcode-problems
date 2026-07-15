// @leetcode id=3227 questionId=3462 slug=vowels-game-in-a-string lang=cpp site=leetcode.com title="Vowels Game in a String"
class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        }
        return false;
    }
};
