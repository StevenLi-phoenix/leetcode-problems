// @leetcode id=916 questionId=952 slug=word-subsets lang=cpp site=leetcode.com title="Word Subsets"
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Compute the max frequency requirement from words2
        int maxFreq[26] = {};
        for (auto& b : words2) {
            int freq[26] = {};
            for (char c : b) freq[c - 'a']++;
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        
        vector<string> result;
        for (auto& a : words1) {
            int freq[26] = {};
            for (char c : a) freq[c - 'a']++;
            bool universal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    universal = false;
                    break;
                }
            }
            if (universal) result.push_back(a);
        }
        return result;
    }
};
