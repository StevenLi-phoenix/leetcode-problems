// @leetcode id=3856 questionId=4229 slug=trim-trailing-vowels lang=cpp site=leetcode.com title="Trim Trailing Vowels"
class Solution {
public:
    string trimTrailingVowels(string s) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int end = s.size();
        while (end > 0 && isVowel(s[end - 1])) --end;
        return s.substr(0, end);
    }
};
