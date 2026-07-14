// @leetcode id=2351 questionId=2427 slug=first-letter-to-appear-twice lang=cpp site=leetcode.com title="First Letter to Appear Twice"
class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> seen(26, false);
        for (char c : s) {
            if (seen[c - 'a']) return c;
            seen[c - 'a'] = true;
        }
        return '?';
    }
};
