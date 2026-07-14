// @leetcode id=3775 questionId=4157 slug=reverse-words-with-same-vowel-count lang=cpp site=leetcode.com title="Reverse Words With Same Vowel Count"
class Solution {
public:
    int vowelCount(const string& w) {
        int count = 0;
        for (char c : w) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
        }
        return count;
    }

    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string w;
        while (iss >> w) words.push_back(w);

        int target = vowelCount(words[0]);
        for (int i = 1; i < (int)words.size(); i++) {
            if (vowelCount(words[i]) == target) {
                reverse(words[i].begin(), words[i].end());
            }
        }

        string result;
        for (int i = 0; i < (int)words.size(); i++) {
            if (i > 0) result += ' ';
            result += words[i];
        }
        return result;
    }
};
