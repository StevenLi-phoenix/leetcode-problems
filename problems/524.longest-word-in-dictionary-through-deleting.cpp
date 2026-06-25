// @leetcode id=524 questionId=524 slug=longest-word-in-dictionary-through-deleting lang=cpp site=leetcode.com title="Longest Word in Dictionary through Deleting"
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        auto isSubseq = [&](const string& word) {
            int j = 0;
            for (int i = 0; i < (int)s.size() && j < (int)word.size(); i++) {
                if (s[i] == word[j]) j++;
            }
            return j == (int)word.size();
        };
        
        string result = "";
        for (const string& word : dictionary) {
            if (isSubseq(word)) {
                if (word.size() > result.size() || 
                    (word.size() == result.size() && word < result)) {
                    result = word;
                }
            }
        }
        return result;
    }
};
