// @leetcode id=1221 questionId=1341 slug=split-a-string-in-balanced-strings lang=cpp site=leetcode.com title="Split a String in Balanced Strings"
class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int balance = 0;

        for (char c : s) {
            balance += (c == 'R' ? 1 : -1);
            if (balance == 0) {
                count++;
            }
        }

        return count;
    }
};
