// @leetcode id=1704 questionId=1823 slug=determine-if-string-halves-are-alike lang=cpp site=leetcode.com title="Determine if String Halves Are Alike"
class Solution {
public:
    bool halvesAreAlike(string s) {
        auto isVowel = [](char c) {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int n = s.size();
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n / 2; i++) if (isVowel(s[i])) count1++;
        for (int i = n / 2; i < n; i++) if (isVowel(s[i])) count2++;
        return count1 == count2;
    }
};
