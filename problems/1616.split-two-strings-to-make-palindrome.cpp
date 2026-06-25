// @leetcode id=1616 questionId=1739 slug=split-two-strings-to-make-palindrome lang=cpp site=leetcode.com title="Split Two Strings to Make Palindrome"
class Solution {
public:
    bool isPalin(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    
    // Check if a_prefix + b_suffix can form palindrome
    bool check(string& a, string& b) {
        int n = a.size();
        int l = 0, r = n - 1;
        while (l < r && a[l] == b[r]) {
            l++; r--;
        }
        // Now either l >= r (entirely matched, always palindrome)
        // Or we need the middle a[l..r] or b[l..r] to be palindrome
        if (l >= r) return true;
        return isPalin(a, l, r) || isPalin(b, l, r);
    }
    
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};
