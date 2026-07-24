// @leetcode id=290 questionId=290 slug=word-pattern lang=cpp site=leetcode.com title="Word Pattern"
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) words.push_back(word);

        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        for (int i = 0; i < (int)pattern.size(); i++) {
            char c = pattern[i];
            const string& w = words[i];

            if (charToWord.count(c) && charToWord[c] != w) return false;
            if (wordToChar.count(w) && wordToChar[w] != c) return false;

            charToWord[c] = w;
            wordToChar[w] = c;
        }
        return true;
    }
};
