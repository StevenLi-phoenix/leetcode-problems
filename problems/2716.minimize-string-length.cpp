// @leetcode id=2716 questionId=2825 slug=minimize-string-length lang=cpp site=leetcode.com title="Minimize String Length"
class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> distinct(s.begin(), s.end());
        return distinct.size();
    }
};
