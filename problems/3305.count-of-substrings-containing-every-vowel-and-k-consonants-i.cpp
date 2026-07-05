// @leetcode id=3305 questionId=3570 slug=count-of-substrings-containing-every-vowel-and-k-consonants-i lang=cpp site=leetcode.com title="Count of Substrings Containing Every Vowel and K Consonants I"
class Solution {
public:
    int countOfSubstrings(string word, int k) {
        auto isVowel = [](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };
        int n = word.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<char> vowels;
            int consonants = 0;
            for (int j = i; j < n; ++j) {
                if (isVowel(word[j])) vowels.insert(word[j]);
                else ++consonants;
                if (consonants > k) break;
                if (vowels.size() == 5 && consonants == k) ++ans;
            }
        }
        return ans;
    }
};
