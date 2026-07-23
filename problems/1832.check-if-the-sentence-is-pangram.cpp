// @leetcode id=1832 questionId=1960 slug=check-if-the-sentence-is-pangram lang=cpp site=leetcode.com title="Check if the Sentence Is Pangram"
class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool seen[26] = {false};
        for (char c : sentence) seen[c - 'a'] = true;
        for (int i = 0; i < 26; i++) {
            if (!seen[i]) return false;
        }
        return true;
    }
};
