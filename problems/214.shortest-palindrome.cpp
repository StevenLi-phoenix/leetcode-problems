// @leetcode id=214 questionId=214 slug=shortest-palindrome lang=cpp site=leetcode.com title="Shortest Palindrome"
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;

        string rev(s.rbegin(), s.rend());
        string combined = s + "#" + rev;
        int n = combined.size();

        vector<int> fail(n, 0);
        for (int i = 1; i < n; ++i) {
            int len = fail[i - 1];
            while (len > 0 && combined[i] != combined[len]) len = fail[len - 1];
            if (combined[i] == combined[len]) ++len;
            fail[i] = len;
        }

        int palindromePrefixLen = fail[n - 1];
        string suffixToPrepend = rev.substr(0, s.size() - palindromePrefixLen);
        return suffixToPrepend + s;
    }
};
