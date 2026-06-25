// @leetcode id=1768 questionId=1894 slug=merge-strings-alternately lang=cpp site=leetcode.com title="Merge Strings Alternately"
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;
        while (i < (int)word1.size() || j < (int)word2.size()) {
            if (i < (int)word1.size()) result += word1[i++];
            if (j < (int)word2.size()) result += word2[j++];
        }
        return result;
    }
};
