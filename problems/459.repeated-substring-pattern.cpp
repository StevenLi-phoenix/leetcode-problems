// @leetcode id=459 questionId=459 slug=repeated-substring-pattern lang=cpp site=leetcode.com title="Repeated Substring Pattern"
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = (s + s).substr(1, 2 * s.size() - 2);
        return doubled.find(s) != string::npos;
    }
};
