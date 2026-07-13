// @leetcode id=1347 questionId=1469 slug=minimum-number-of-steps-to-make-two-strings-anagram lang=cpp site=leetcode.com title="Minimum Number of Steps to Make Two Strings Anagram"
class Solution {
public:
    int minSteps(string s, string t) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;

        int steps = 0;
        for (int i = 0; i < 26; i++) if (count[i] > 0) steps += count[i];
        return steps;
    }
};
