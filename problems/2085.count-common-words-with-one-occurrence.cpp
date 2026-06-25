// @leetcode id=2085 questionId=2190 slug=count-common-words-with-one-occurrence lang=cpp site=leetcode.com title="Count Common Words With One Occurrence"
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freq1, freq2;

        for (const string& word : words1) {
            freq1[word]++;
        }

        for (const string& word : words2) {
            freq2[word]++;
        }

        int count = 0;
        for (const auto& [word, f] : freq1) {
            if (f == 1 && freq2[word] == 1) {
                count++;
            }
        }

        return count;
    }
};
