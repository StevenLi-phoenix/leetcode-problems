// @leetcode id=2309 questionId=1363 slug=greatest-english-letter-in-upper-and-lower-case lang=cpp site=leetcode.com title="Greatest English Letter in Upper and Lower Case"
class Solution {
public:
    string greatestLetter(string s) {
        int seenLower = 0, seenUpper = 0;
        for (char c : s) {
            if (islower((unsigned char)c)) seenLower |= (1 << (c - 'a'));
            else seenUpper |= (1 << (c - 'A'));
        }
        for (int i = 25; i >= 0; i--) {
            if ((seenLower & (1 << i)) && (seenUpper & (1 << i))) {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};
