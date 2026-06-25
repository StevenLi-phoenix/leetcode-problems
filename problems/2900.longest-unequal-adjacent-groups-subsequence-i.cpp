// @leetcode id=2900 questionId=3143 slug=longest-unequal-adjacent-groups-subsequence-i lang=cpp site=leetcode.com title="Longest Unequal Adjacent Groups Subsequence I"
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        result.push_back(words[0]);
        int lastGroup = groups[0];

        for (int i = 1; i < words.size(); i++) {
            if (groups[i] != lastGroup) {
                result.push_back(words[i]);
                lastGroup = groups[i];
            }
        }

        return result;
    }
};
