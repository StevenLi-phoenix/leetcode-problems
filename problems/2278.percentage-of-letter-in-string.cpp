// @leetcode id=2278 questionId=2365 slug=percentage-of-letter-in-string lang=cpp site=leetcode.com title="Percentage of Letter in String"
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for (char c : s) if (c == letter) count++;
        return count * 100 / (int)s.size();
    }
};
