// @leetcode id=126 questionId=126 slug=word-ladder-ii lang=cpp site=leetcode.com title="Word Ladder II"
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (!wordSet.count(endWord)) return result;
        wordSet.erase(beginWord);

        // Level-by-level BFS, recording every parent that reaches a word at
        // the shortest distance, so all shortest paths can be reconstructed.
        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel = {beginWord};
        bool found = false;

        while (!currentLevel.empty() && !found) {
            unordered_set<string> nextLevel;
            unordered_set<string> toRemove;
            for (const string& word : currentLevel) {
                string cand = word;
                for (int i = 0; i < (int)cand.size(); i++) {
                    char original = cand[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        cand[i] = c;
                        if (wordSet.count(cand)) {
                            nextLevel.insert(cand);
                            toRemove.insert(cand);
                            parents[cand].push_back(word);
                            if (cand == endWord) found = true;
                        }
                    }
                    cand[i] = original;
                }
            }
            for (const string& w : toRemove) wordSet.erase(w);
            currentLevel = nextLevel;
        }

        if (!found) return result;

        vector<string> path = {endWord};
        function<void()> backtrack = [&]() {
            if (path.back() == beginWord) {
                vector<string> rev(path.rbegin(), path.rend());
                result.push_back(rev);
                return;
            }
            for (const string& p : parents[path.back()]) {
                path.push_back(p);
                backtrack();
                path.pop_back();
            }
        };
        backtrack();
        return result;
    }
};
