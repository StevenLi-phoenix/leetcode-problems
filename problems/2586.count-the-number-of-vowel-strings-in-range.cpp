// @leetcode id=2586 questionId=2654 slug=count-the-number-of-vowel-strings-in-range lang=cpp site=leetcode.com title="Count the Number of Vowel Strings in Range"
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (isVowel(words[i].front()) && isVowel(words[i].back())) count++;
        }
        return count;
    }
};
