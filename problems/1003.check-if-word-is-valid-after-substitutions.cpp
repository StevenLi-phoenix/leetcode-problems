// @leetcode id=1003 questionId=1045 slug=check-if-word-is-valid-after-substitutions lang=cpp site=leetcode.com title="Check If Word Is Valid After Substitutions"
class Solution {
public:
    bool isValid(string s) {
        string stack;
        for (char c : s) {
            stack.push_back(c);
            if (stack.size() >= 3 && stack.substr(stack.size() - 3) == "abc") {
                stack.erase(stack.size() - 3);
            }
        }
        return stack.empty();
    }
};
