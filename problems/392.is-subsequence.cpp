// @leetcode id=392 questionId=392 slug=is-subsequence lang=cpp site=leetcode.com title="Is Subsequence"
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char c : t) {
            if (i < (int)s.size() && s[i] == c) i++;
        }
        return i == (int)s.size();
    }
};
