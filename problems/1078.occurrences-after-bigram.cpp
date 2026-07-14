// @leetcode id=1078 questionId=1156 slug=occurrences-after-bigram lang=cpp site=leetcode.com title="Occurrences After Bigram"
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        stringstream ss(text);
        string w;
        while (ss >> w) words.push_back(w);

        vector<string> result;
        for (size_t i = 0; i + 2 < words.size(); i++) {
            if (words[i] == first && words[i + 1] == second) {
                result.push_back(words[i + 2]);
            }
        }
        return result;
    }
};
