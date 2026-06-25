// @leetcode id=678 questionId=678 slug=valid-parenthesis-string lang=cpp site=leetcode.com title="Valid Parenthesis String"
class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        for (char c : s) {
            if (c == '(') { lo++; hi++; }
            else if (c == ')') { lo--; hi--; }
            else { lo--; hi++; } // '*' treated as ')' for lo, '(' for hi
            if (hi < 0) return false; // too many ')'
            lo = max(lo, 0); // lo can't go negative (excess ')' absorbed by '*')
        }
        return lo == 0;
    }
};
