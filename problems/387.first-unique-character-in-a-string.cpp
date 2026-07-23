// @leetcode id=387 questionId=387 slug=first-unique-character-in-a-string lang=cpp site=leetcode.com title="First Unique Character in a String"
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;

        for (int i = 0; i < (int)s.size(); i++) {
            if (count[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
