// @leetcode id=3504 questionId=3808 slug=longest-palindrome-after-substring-concatenation-ii lang=cpp site=leetcode.com title="Longest Palindrome After Substring Concatenation II"
class Solution {
public:
    // end[i] = length of the longest palindromic substring of u ending at index i.
    vector<int> palindromeLengthsEndingAt(const string& u) {
        int n = u.size();
        vector<int> end(n, 0);
        for (int c = 0; c < n; c++) {
            int l = c, r = c;
            while (l >= 0 && r < n && u[l] == u[r]) {
                end[r] = max(end[r], r - l + 1);
                l--; r++;
            }
        }
        for (int c = 0; c + 1 < n; c++) {
            int l = c, r = c + 1;
            while (l >= 0 && r < n && u[l] == u[r]) {
                end[r] = max(end[r], r - l + 1);
                l--; r++;
            }
        }
        return end;
    }

    int longestPalindrome(string s, string t) {
        int n = s.size(), m = t.size();

        // g[i][j]: length of the chain s[i]=t[j], s[i-1]=t[j+1], ... i.e. the
        // matched run using s ending at i (going backwards) against t
        // starting at j (going forwards). For a chosen A=s[p..i] and
        // B=t[j..q], this chain forms the outer mirrored pairs of A+B:
        // A's first char pairs with B's last char, and so on inward.
        vector<vector<int>> g(n, vector<int>(m, 0));

        vector<int> endS = palindromeLengthsEndingAt(s);
        vector<int> endT = palindromeLengthsEndingAt(t);
        string sr(s.rbegin(), s.rend());
        vector<int> endSr = palindromeLengthsEndingAt(sr);
        vector<int> startS(n);
        for (int i = 0; i < n; i++) startS[i] = endSr[n - 1 - i];

        int ans = 0;
        for (int v : endS) ans = max(ans, v);
        for (int v : endT) ans = max(ans, v);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] == t[j]) {
                    g[i][j] = 1 + ((i > 0 && j < m - 1) ? g[i - 1][j + 1] : 0);
                    int L = g[i][j];
                    // Case X: B is fully consumed by the chain; A has a
                    // trailing extra part (starting right after i) that must
                    // itself be a palindrome.
                    int cand1 = 2 * L + (i + 1 < n ? startS[i + 1] : 0);
                    // Case Y: A is fully consumed by the chain; B has a
                    // leading extra part (ending right before j) that must
                    // itself be a palindrome.
                    int cand2 = 2 * L + (j - 1 >= 0 ? endT[j - 1] : 0);
                    ans = max({ans, cand1, cand2});
                }
            }
        }
        return ans;
    }
};
