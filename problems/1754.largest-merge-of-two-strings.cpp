// @leetcode id=1754 questionId=1880 slug=largest-merge-of-two-strings lang=cpp site=leetcode.com title="Largest Merge Of Two Strings"
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge = "";
        int i = 0, j = 0;
        while (i < (int)word1.size() && j < (int)word2.size()) {
            if (word1.substr(i) >= word2.substr(j)) {
                merge += word1[i++];
            } else {
                merge += word2[j++];
            }
        }
        while (i < (int)word1.size()) merge += word1[i++];
        while (j < (int)word2.size()) merge += word2[j++];
        return merge;
    }
};
