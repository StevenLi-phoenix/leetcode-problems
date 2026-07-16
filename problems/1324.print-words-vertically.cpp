// @leetcode id=1324 questionId=1449 slug=print-words-vertically lang=cpp site=leetcode.com title="Print Words Vertically"
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        int maxLen = 0;
        while (ss >> word) {
            words.push_back(word);
            maxLen = max(maxLen, (int)word.size());
        }

        vector<string> result;
        for (int col = 0; col < maxLen; col++) {
            string line;
            for (auto& w : words) {
                line += (col < (int)w.size()) ? w[col] : ' ';
            }
            while (!line.empty() && line.back() == ' ') line.pop_back();
            result.push_back(line);
        }
        return result;
    }
};
