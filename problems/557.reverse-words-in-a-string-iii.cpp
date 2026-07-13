// @leetcode id=557 questionId=557 slug=reverse-words-in-a-string-iii lang=cpp site=leetcode.com title="Reverse Words in a String III"
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};
