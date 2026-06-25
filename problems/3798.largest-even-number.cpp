// @leetcode id=3798 questionId=4179 slug=largest-even-number lang=cpp site=leetcode.com title="Largest Even Number"
class Solution {
public:
    string largestEven(string s) {
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '2') {
                return s.substr(0, i + 1);
            }
        }
        return "";
    }
};
