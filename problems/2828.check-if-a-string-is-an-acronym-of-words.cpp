// @leetcode id=2828 questionId=2977 slug=check-if-a-string-is-an-acronym-of-words lang=cpp site=leetcode.com title="Check if a String Is an Acronym of Words"
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.size()) return false;
        for (int i = 0; i < (int)words.size(); i++) {
            if (words[i][0] != s[i]) return false;
        }
        return true;
    }
};
