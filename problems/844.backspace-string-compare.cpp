// @leetcode id=844 questionId=874 slug=backspace-string-compare lang=cpp site=leetcode.com title="Backspace String Compare"
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        auto build = [](const string& str) {
            string res;
            for (char c : str) {
                if (c == '#') {
                    if (!res.empty()) res.pop_back();
                } else {
                    res.push_back(c);
                }
            }
            return res;
        };
        return build(s) == build(t);
    }
};
