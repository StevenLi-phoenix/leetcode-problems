// @leetcode id=1455 questionId=1566 slug=check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence lang=cpp site=leetcode.com title="Check If a Word Occurs As a Prefix of Any Word in a Sentence"
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int idx = 0;
        while (ss >> word) {
            idx++;
            if (word.compare(0, searchWord.size(), searchWord) == 0) return idx;
        }
        return -1;
    }
};
