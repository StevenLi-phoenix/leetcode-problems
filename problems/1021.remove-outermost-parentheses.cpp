// @leetcode id=1021 questionId=1078 slug=remove-outermost-parentheses lang=cpp site=leetcode.com title="Remove Outermost Parentheses"
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int depth = 0;
        for (char c : s) {
            if (c == '(') {
                if (depth > 0) res += c;
                depth++;
            } else {
                depth--;
                if (depth > 0) res += c;
            }
        }
        return res;
    }
};
