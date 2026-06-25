// @leetcode id=1332 questionId=1454 slug=remove-palindromic-subsequences lang=cpp site=leetcode.com title="Remove Palindromic Subsequences"
class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;

        string rev = s;
        reverse(rev.begin(), rev.end());

        if (s == rev) return 1;
        return 2;
    }
};
