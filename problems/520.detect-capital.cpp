// @leetcode id=520 questionId=520 slug=detect-capital lang=cpp site=leetcode.com title="Detect Capital"
class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCount = 0;
        for (char c : word) if (isupper(c)) ++upperCount;

        if (upperCount == 0 || upperCount == (int)word.size()) return true;
        return upperCount == 1 && isupper(word[0]);
    }
};
