// @leetcode id=2002 questionId=2130 slug=maximum-product-of-the-length-of-two-palindromic-subsequences lang=cpp site=leetcode.com title="Maximum Product of the Length of Two Palindromic Subsequences"
class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        int full = 1 << n;
        vector<bool> isPalin(full, false);
        vector<int> popcnt(full, 0);

        for (int mask = 1; mask < full; mask++) {
            string sub;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) sub += s[i];
            }
            popcnt[mask] = __builtin_popcount(mask);

            bool palin = true;
            for (int l = 0, r = (int)sub.size() - 1; l < r; l++, r--) {
                if (sub[l] != sub[r]) { palin = false; break; }
            }
            isPalin[mask] = palin;
        }

        int best = 0;
        for (int m1 = 1; m1 < full; m1++) {
            if (!isPalin[m1]) continue;
            for (int m2 = 1; m2 < full; m2++) {
                if ((m1 & m2) != 0 || !isPalin[m2]) continue;
                best = max(best, popcnt[m1] * popcnt[m2]);
            }
        }
        return best;
    }
};
