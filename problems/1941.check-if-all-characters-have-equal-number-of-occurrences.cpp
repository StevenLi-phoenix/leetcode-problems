// @leetcode id=1941 questionId=2053 slug=check-if-all-characters-have-equal-number-of-occurrences lang=cpp site=leetcode.com title="Check if All Characters Have Equal Number of Occurrences"
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        int freq = -1;
        for (int c : count) {
            if (c == 0) continue;
            if (freq == -1) freq = c;
            else if (c != freq) return false;
        }
        return true;
    }
};
