// @leetcode id=1930 questionId=2059 slug=unique-length-3-palindromic-subsequences lang=cpp site=leetcode.com title="Unique Length-3 Palindromic Subsequences"
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int first[26], last[26];
        fill(first, first + 26, -1);
        fill(last, last + 26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int count = 0;
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1 || last[c] - first[c] < 2) continue;
            unordered_set<char> between;
            for (int i = first[c] + 1; i < last[c]; i++) between.insert(s[i]);
            count += between.size();
        }
        return count;
    }
};
