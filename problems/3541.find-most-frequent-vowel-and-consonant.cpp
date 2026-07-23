// @leetcode id=3541 questionId=3872 slug=find-most-frequent-vowel-and-consonant lang=cpp site=leetcode.com title="Find Most Frequent Vowel and Consonant"
class Solution {
public:
    int maxFreqSum(string s) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;

        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int maxVowel = 0, maxConsonant = 0;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (isVowel(c)) maxVowel = max(maxVowel, count[i]);
            else maxConsonant = max(maxConsonant, count[i]);
        }
        return maxVowel + maxConsonant;
    }
};
