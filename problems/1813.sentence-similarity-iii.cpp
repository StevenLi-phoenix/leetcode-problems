// @leetcode id=1813 questionId=1923 slug=sentence-similarity-iii lang=cpp site=leetcode.com title="Sentence Similarity III"
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> w1 = split(sentence1);
        vector<string> w2 = split(sentence2);
        if (w1.size() > w2.size()) swap(w1, w2);

        int i = 0;
        while (i < (int)w1.size() && w1[i] == w2[i]) i++;

        int j = 0;
        while (j < (int)w1.size() - i && w1[w1.size() - 1 - j] == w2[w2.size() - 1 - j]) j++;

        return i + j >= (int)w1.size();
    }

private:
    vector<string> split(const string& s) {
        vector<string> words;
        istringstream iss(s);
        string w;
        while (iss >> w) words.push_back(w);
        return words;
    }
};
