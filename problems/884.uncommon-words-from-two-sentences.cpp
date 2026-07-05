// @leetcode id=884 questionId=920 slug=uncommon-words-from-two-sentences lang=cpp site=leetcode.com title="Uncommon Words from Two Sentences"
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        istringstream iss(s1 + " " + s2);
        string word;
        while (iss >> word) count[word]++;

        vector<string> ans;
        for (auto& [w, c] : count) {
            if (c == 1) ans.push_back(w);
        }
        return ans;
    }
};
