// @leetcode id=680 questionId=680 slug=valid-palindrome-ii lang=cpp site=leetcode.com title="Valid Palindrome II"
class Solution {
public:
    bool validPalindrome(string s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            if (s[lo] != s[hi]) {
                return isPalindrome(s, lo + 1, hi) || isPalindrome(s, lo, hi - 1);
            }
            ++lo;
            --hi;
        }
        return true;
    }

private:
    bool isPalindrome(const string& s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo] != s[hi]) return false;
            ++lo;
            --hi;
        }
        return true;
    }
};
