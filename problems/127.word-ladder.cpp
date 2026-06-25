// @leetcode id=127 questionId=127 slug=word-ladder lang=cpp site=leetcode.com title="Word Ladder"
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();
            
            for (int i = 0; i < (int)word.size(); i++) {
                string next = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    next[i] = c;
                    if (next == endWord) return steps + 1;
                    if (wordSet.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push({next, steps + 1});
                    }
                }
            }
        }
        return 0;
    }
};
