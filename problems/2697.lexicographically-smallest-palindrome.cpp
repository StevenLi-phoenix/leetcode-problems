// @leetcode id=2697 questionId=2816 slug=lexicographically-smallest-palindrome lang=cpp site=leetcode.com title="Lexicographically Smallest Palindrome"
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                char c = min(s[l], s[r]);
                s[l] = s[r] = c;
            }
            l++; r--;
        }
        return s;
    }
};
