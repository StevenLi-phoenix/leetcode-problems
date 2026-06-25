// @leetcode id=2506 questionId=2594 slug=count-pairs-of-similar-strings lang=cpp site=leetcode.com title="Count Pairs Of Similar Strings"
class Solution {
public:
    int similarPairs(vector<string>& words) {
        map<string, int> freq;
        
        for (const string& word : words) {
            string normalized = word;
            sort(normalized.begin(), normalized.end());
            normalized.erase(unique(normalized.begin(), normalized.end()), normalized.end());
            freq[normalized]++;
        }
        
        int count = 0;
        for (auto& [key, cnt] : freq) {
            count += cnt * (cnt - 1) / 2;
        }
        
        return count;
    }
};
