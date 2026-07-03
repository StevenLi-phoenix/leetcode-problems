// @leetcode id=3561 questionId=3860 slug=resulting-string-after-adjacent-removals lang=cpp site=leetcode.com title="Resulting String After Adjacent Removals"
class Solution {
public:
    string resultingString(string s) {
        string stack;
        for (char c : s) {
            if (!stack.empty()) {
                int diff = abs(stack.back() - c);
                if (diff == 1 || diff == 25) {
                    stack.pop_back();
                    continue;
                }
            }
            stack.push_back(c);
        }
        return stack;
    }
};
