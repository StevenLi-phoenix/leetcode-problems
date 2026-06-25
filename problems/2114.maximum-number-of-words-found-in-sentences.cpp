// @leetcode id=2114 questionId=2219 slug=maximum-number-of-words-found-in-sentences lang=cpp site=leetcode.com title="Maximum Number of Words Found in Sentences"
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;

        for (const string& s : sentences) {
            int words = 1;
            for (char c : s) {
                if (c == ' ') {
                    words++;
                }
            }
            maxWords = max(maxWords, words);
        }

        return maxWords;
    }
};
