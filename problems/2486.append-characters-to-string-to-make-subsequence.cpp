// @leetcode id=2486 questionId=2572 slug=append-characters-to-string-to-make-subsequence lang=cpp site=leetcode.com title="Append Characters to String to Make Subsequence"
class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        int n = t.size();
        for (int i = 0; i < (int)s.size() && j < n; i++) {
            if (s[i] == t[j]) j++;
        }
        return n - j;
    }
};
