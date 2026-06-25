// @leetcode id=2696 questionId=2800 slug=minimum-string-length-after-removing-substrings lang=cpp site=leetcode.com title="Minimum String Length After Removing Substrings"
class Solution {
public:
    int minLength(string s) {
        string stack;
        for (char c : s) {
            stack.push_back(c);
            if (stack.size() >= 2) {
                int n = stack.size();
                if ((stack[n-2] == 'A' && stack[n-1] == 'B') ||
                    (stack[n-2] == 'C' && stack[n-1] == 'D')) {
                    stack.pop_back();
                    stack.pop_back();
                }
            }
        }
        return stack.length();
    }
};
