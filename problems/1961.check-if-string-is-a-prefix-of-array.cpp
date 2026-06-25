// @leetcode id=1961 questionId=2093 slug=check-if-string-is-a-prefix-of-array lang=cpp site=leetcode.com title="Check If String Is a Prefix of Array"
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string prefix = "";
        for (const string& word : words) {
            prefix += word;
            if (prefix == s) return true;
            if (prefix.length() > s.length()) return false;
        }
        return false;
    }
};
