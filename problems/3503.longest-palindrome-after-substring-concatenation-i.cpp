// @leetcode id=3503 questionId=3793 slug=longest-palindrome-after-substring-concatenation-i lang=cpp site=leetcode.com title="Longest Palindrome After Substring Concatenation I"
class Solution {
public:
    int longestPalindrome(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<bool>> palS(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) palS[i][j] = true;
                else if (s[i] == s[j] && (j == i + 1 || palS[i + 1][j - 1])) palS[i][j] = true;
            }
        }
        vector<vector<bool>> palT(m, vector<bool>(m, false));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = i; j < m; j++) {
                if (i == j) palT[i][j] = true;
                else if (t[i] == t[j] && (j == i + 1 || palT[i + 1][j - 1])) palT[i][j] = true;
            }
        }

        vector<int> palLenFromLeft(n + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= i; j--) {
                if (palS[i][j]) { palLenFromLeft[i] = j - i + 1; break; }
            }
        }
        vector<int> palLenEndingAt(m, 0);
        for (int j = 0; j < m; j++) {
            for (int i = 0; i <= j; i++) {
                if (palT[i][j]) { palLenEndingAt[j] = j - i + 1; break; }
            }
        }

        int best = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a = i, b = j, cnt = 0;
                while (a < n && b >= 0 && s[a] == t[b]) { cnt++; a++; b--; }
                int crossLen = 2 * cnt;
                int extS = (a < n) ? palLenFromLeft[a] : 0;
                int extT = (b >= 0) ? palLenEndingAt[b] : 0;
                best = max(best, crossLen + max(extS, extT));
            }
        }
        return best;
    }
};
