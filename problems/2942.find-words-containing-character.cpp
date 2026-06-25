// @leetcode id=2942 questionId=3194 slug=find-words-containing-character lang=cpp site=leetcode.com title="Find Words Containing Character"
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != string::npos) {
                result.push_back(i);
            }
        }
        return result;
    }
};
