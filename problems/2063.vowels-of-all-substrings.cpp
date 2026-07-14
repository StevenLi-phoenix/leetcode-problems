// @leetcode id=2063 questionId=2187 slug=vowels-of-all-substrings lang=cpp site=leetcode.com title="Vowels of All Substrings"
class Solution {
public:
    long long countVowels(string word) {
        int n = word.size();
        long long total = 0;
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                total += (long long)(i + 1) * (n - i);
            }
        }
        return total;
    }
};
