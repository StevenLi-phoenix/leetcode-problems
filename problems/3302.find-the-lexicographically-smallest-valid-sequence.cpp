// @leetcode id=3302 questionId=3584 slug=find-the-lexicographically-smallest-valid-sequence lang=cpp site=leetcode.com title="Find the Lexicographically Smallest Valid Sequence"
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        // suf[i] = number of chars from suffix of word2 that can be matched
        // as a subsequence in word1[i..n-1] (matching from right side of word2)
        vector<int> suf(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                suf[i] = suf[i + 1] + 1;
                j--;
            } else {
                suf[i] = suf[i + 1];
            }
        }
        // Fill remaining positions
        for (int i = (j >= 0 ? -1 : (int)(n - 1 - (m - 1 - j))); i >= 0; i--) {
            if (suf[i] == 0) suf[i] = suf[i + 1];
        }
        // Recompute suf properly
        fill(suf.begin(), suf.end(), 0);
        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (j >= 0 && word1[i] == word2[j]) {
                suf[i]++;
                j--;
            }
        }
        
        vector<int> result(m, -1);
        bool usedWild = false;
        j = 0;
        
        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                result[j++] = i;
            } else if (!usedWild && i + 1 <= n && suf[i + 1] >= m - j - 1) {
                usedWild = true;
                result[j++] = i;
            }
        }
        
        if (j < m) return {};
        return result;
    }
};
