// @leetcode id=921 questionId=957 slug=minimum-add-to-make-parentheses-valid lang=cpp site=leetcode.com title="Minimum Add to Make Parentheses Valid"
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, needed = 0;
        for (char c : s) {
            if (c == '(') open++;
            else {
                if (open > 0) open--;
                else needed++;
            }
        }
        return open + needed;
    }
};
