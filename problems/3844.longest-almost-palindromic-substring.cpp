// @leetcode id=3844 questionId=4221 slug=longest-almost-palindromic-substring lang=cpp site=leetcode.com title="Longest Almost-Palindromic Substring"
class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();
        const int FULL = -1;
        // off[L][R] = number of matching outer pairs before first mismatch, or FULL if s[L..R] is a palindrome.
        vector<vector<int>> off(n, vector<int>(n, 0));

        for (int L = 0; L < n; L++) off[L][L] = FULL;
        for (int L = 0; L + 1 < n; L++) {
            int R = L + 1;
            off[L][R] = (s[L] == s[R]) ? FULL : 0;
        }
        for (int len = 3; len <= n; len++) {
            for (int L = 0; L + len - 1 < n; L++) {
                int R = L + len - 1;
                if (s[L] != s[R]) {
                    off[L][R] = 0;
                } else {
                    int inner = off[L + 1][R - 1];
                    off[L][R] = (inner == FULL) ? FULL : inner + 1;
                }
            }
        }

        int best = 0;
        for (int L = 0; L < n; L++) {
            for (int R = L + 1; R < n; R++) {
                int o = off[L][R];
                bool valid = false;
                if (o == FULL) {
                    valid = true;
                } else {
                    int l2 = L + o, r2 = R - o;
                    if (l2 + 1 <= r2 && off[l2 + 1][r2] == FULL) valid = true;
                    if (l2 <= r2 - 1 && off[l2][r2 - 1] == FULL) valid = true;
                }
                if (valid) best = max(best, R - L + 1);
            }
        }
        return best;
    }
};
