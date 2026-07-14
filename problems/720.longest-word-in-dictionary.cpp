// @leetcode id=720 questionId=720 slug=longest-word-in-dictionary lang=cpp site=leetcode.com title="Longest Word in Dictionary"
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> buildable;
        buildable.insert("");
        string best;
        for (auto& w : words) {
            if (buildable.count(w.substr(0, w.size() - 1))) {
                buildable.insert(w);
                if (w.size() > best.size()) best = w;
            }
        }
        return best;
    }
};
