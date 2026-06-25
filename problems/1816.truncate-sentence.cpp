// @leetcode id=1816 questionId=1944 slug=truncate-sentence lang=cpp site=leetcode.com title="Truncate Sentence"
class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
                if (count == k) {
                    return s.substr(0, i);
                }
            }
        }
        return s;
    }
};
