// @leetcode id=3461 questionId=3768 slug=check-if-digits-are-equal-in-string-after-operations-i lang=cpp site=leetcode.com title="Check If Digits Are Equal in String After Operations I"
class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string next;
            for (int i = 0; i + 1 < (int)s.size(); i++) {
                int d = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
                next += ('0' + d);
            }
            s = next;
        }
        return s[0] == s[1];
    }
};
