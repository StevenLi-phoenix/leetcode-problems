// @leetcode id=3794 questionId=4177 slug=reverse-string-prefix lang=cpp site=leetcode.com title="Reverse String Prefix"
class Solution {
public:
    string reversePrefix(string s, int k) {
        reverse(s.begin(), s.begin() + k);
        return s;
    }
};
