// @leetcode id=151 questionId=151 slug=reverse-words-in-a-string lang=cpp site=leetcode.com title="Reverse Words in a String"
class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word) words.push_back(word);

        reverse(words.begin(), words.end());

        string result;
        for (size_t i = 0; i < words.size(); i++) {
            if (i > 0) result += ' ';
            result += words[i];
        }
        return result;
    }
};
