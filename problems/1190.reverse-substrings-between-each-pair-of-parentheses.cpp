// @leetcode id=1190 questionId=1298 slug=reverse-substrings-between-each-pair-of-parentheses lang=cpp site=leetcode.com title="Reverse Substrings Between Each Pair of Parentheses"
class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stack;
        stack.push_back("");
        for (char c : s) {
            if (c == '(') {
                stack.push_back("");
            } else if (c == ')') {
                string top = stack.back();
                stack.pop_back();
                reverse(top.begin(), top.end());
                stack.back() += top;
            } else {
                stack.back() += c;
            }
        }
        return stack.back();
    }
};
