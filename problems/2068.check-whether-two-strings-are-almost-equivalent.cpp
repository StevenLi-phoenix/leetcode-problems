// @leetcode id=2068 questionId=2177 slug=check-whether-two-strings-are-almost-equivalent lang=cpp site=leetcode.com title="Check Whether Two Strings are Almost Equivalent"
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int count[26] = {0};
        for (char c : word1) count[c - 'a']++;
        for (char c : word2) count[c - 'a']--;

        for (int i = 0; i < 26; i++) {
            if (abs(count[i]) > 3) return false;
        }
        return true;
    }
};
