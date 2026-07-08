// @leetcode id=65 questionId=65 slug=valid-number lang=cpp site=leetcode.com title="Valid Number"
class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false, seenDot = false, seenExp = false;

        for (int i = 0; i < (int)s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                seenDigit = true;
            } else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
            } else if (c == '.') {
                if (seenDot || seenExp) return false;
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                if (seenExp || !seenDigit) return false;
                seenExp = true;
                seenDigit = false; // require at least one digit after exponent
            } else {
                return false;
            }
        }
        return seenDigit;
    }
};
