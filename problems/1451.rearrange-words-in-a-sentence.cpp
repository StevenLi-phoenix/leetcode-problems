// @leetcode id=1451 questionId=1561 slug=rearrange-words-in-a-sentence lang=cpp site=leetcode.com title="Rearrange Words in a Sentence"
class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        vector<string> words;
        stringstream ss(text);
        string w;
        while (ss >> w) words.push_back(w);

        stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        words[0][0] = toupper(words[0][0]);
        string result;
        for (int i = 0; i < (int)words.size(); i++) {
            if (i) result += ' ';
            result += words[i];
        }
        return result;
    }
};
