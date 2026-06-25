// @leetcode id=3174 questionId=3447 slug=clear-digits lang=cpp site=leetcode.com title="Clear Digits"
class Solution {
public:
    string clearDigits(string s) {
        string stack;
        for (char c : s) {
            if (isalpha(c)) {
                stack += c;
            } else {
                // digit: remove closest non-digit to its left
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
        }
        return stack;
    }
};
