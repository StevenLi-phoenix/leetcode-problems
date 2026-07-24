// @leetcode id=2062 questionId=2186 slug=count-vowel-substrings-of-a-string lang=cpp site=leetcode.com title="Count Vowel Substrings of a String"
class Solution {
public:
    int countVowelSubstrings(string word) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int n = word.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> seen;
            for (int j = i; j < n; j++) {
                if (!isVowel(word[j])) break;
                seen.insert(word[j]);
                if (seen.size() == 5) count++;
            }
        }
        return count;
    }
};
