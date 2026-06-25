// @leetcode id=541 questionId=541 slug=reverse-string-ii lang=cpp site=leetcode.com title="Reverse String II"
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < (int)s.length(); i += 2 * k) {
            int end = min(i + k - 1, (int)s.length() - 1);
            reverse(s.begin() + i, s.begin() + end + 1);
        }
        return s;
    }
};
