// @leetcode id=1160 questionId=1112 slug=find-words-that-can-be-formed-by-characters lang=cpp site=leetcode.com title="Find Words That Can Be Formed by Characters"
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int charCount[26] = {0};
        for (char c : chars) charCount[c - 'a']++;

        int total = 0;
        for (const string& w : words) {
            int wordCount[26] = {0};
            for (char c : w) wordCount[c - 'a']++;

            bool good = true;
            for (int i = 0; i < 26 && good; i++) {
                if (wordCount[i] > charCount[i]) good = false;
            }
            if (good) total += w.size();
        }
        return total;
    }
};
