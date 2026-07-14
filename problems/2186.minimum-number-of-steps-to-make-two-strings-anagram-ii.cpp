// @leetcode id=2186 questionId=2293 slug=minimum-number-of-steps-to-make-two-strings-anagram-ii lang=cpp site=leetcode.com title="Minimum Number of Steps to Make Two Strings Anagram II"
class Solution {
public:
    int minSteps(string s, string t) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;

        int steps = 0;
        for (int c : count) steps += abs(c);
        return steps;
    }
};
