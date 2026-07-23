// @leetcode id=1844 questionId=1954 slug=replace-all-digits-with-characters lang=cpp site=leetcode.com title="Replace All Digits with Characters"
class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < (int)s.size(); i += 2) {
            s[i] = s[i - 1] + (s[i] - '0');
        }
        return s;
    }
};
