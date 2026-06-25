// @leetcode id=3813 questionId=4178 slug=vowel-consonant-score lang=cpp site=leetcode.com title="Vowel-Consonant Score"
class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;

        for (char ch : s) {
            if (isalpha(ch)) {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    v++;
                } else {
                    c++;
                }
            }
        }

        if (c > 0) {
            return v / c;
        }
        return 0;
    }
};
