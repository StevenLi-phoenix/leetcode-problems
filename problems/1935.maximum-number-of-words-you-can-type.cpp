// @leetcode id=1935 questionId=1264 slug=maximum-number-of-words-you-can-type lang=cpp site=leetcode.com title="Maximum Number of Words You Can Type"
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26] = {false};
        for (char c : brokenLetters) broken[c - 'a'] = true;

        int count = 0;
        stringstream ss(text);
        string word;
        while (ss >> word) {
            bool ok = true;
            for (char c : word) {
                if (broken[c - 'a']) { ok = false; break; }
            }
            if (ok) count++;
        }
        return count;
    }
};
