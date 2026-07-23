// @leetcode id=1544 questionId=1666 slug=make-the-string-great lang=cpp site=leetcode.com title="Make The String Great"
class Solution {
public:
    string makeGood(string s) {
        string stack;
        for (char c : s) {
            if (!stack.empty() && abs(stack.back() - c) == 32) {
                stack.pop_back();
            } else {
                stack += c;
            }
        }
        return stack;
    }
};
