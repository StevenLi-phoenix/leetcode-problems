// @leetcode id=5 questionId=5 slug=longest-palindromic-substring lang=cpp site=leetcode.com title="Longest Palindromic Substring"
class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        if (n <= 1) return s;

        int bestStart = 0, bestLen = 1;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // palindrome is s[l+1 .. r-1]
            int len = r - l - 1;
            int start = l + 1;
            if (len > bestLen) {
                bestLen = len;
                bestStart = start;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);       // odd length center
            expand(i, i + 1);   // even length center
        }

        return s.substr(bestStart, bestLen);
    }
};
