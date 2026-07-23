// @leetcode id=1859 questionId=1970 slug=sorting-the-sentence lang=cpp site=leetcode.com title="Sorting the Sentence"
class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string word;
        vector<string> words(10);
        int maxIdx = 0;
        while (ss >> word) {
            int idx = word.back() - '0';
            words[idx] = word.substr(0, word.size() - 1);
            maxIdx = max(maxIdx, idx);
        }

        string result;
        for (int i = 1; i <= maxIdx; i++) {
            if (i > 1) result += ' ';
            result += words[i];
        }
        return result;
    }
};
