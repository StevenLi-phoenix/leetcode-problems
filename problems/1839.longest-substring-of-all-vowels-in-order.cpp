// @leetcode id=1839 questionId=1967 slug=longest-substring-of-all-vowels-in-order lang=cpp site=leetcode.com title="Longest Substring Of All Vowels in Order"
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        string order = "aeiou";
        auto rank = [&](char c) { return order.find(c); };

        int best = 0;
        int n = word.size();
        int start = 0;
        int distinctMask = 1; // bit for word[start]
        for (int i = 1; i < n; i++) {
            if (rank(word[i]) == rank(word[i - 1])) {
                // same vowel, continue
            } else if (rank(word[i]) == rank(word[i - 1]) + 1) {
                distinctMask |= (1 << rank(word[i]));
            } else {
                start = i;
                distinctMask = (1 << rank(word[i]));
            }
            if (distinctMask == 0b11111) best = max(best, i - start + 1);
        }
        return best;
    }
};
