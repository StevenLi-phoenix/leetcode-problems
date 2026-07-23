// @leetcode id=859 questionId=889 slug=buddy-strings lang=cpp site=leetcode.com title="Buddy Strings"
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;

        if (s == goal) {
            int count[26] = {0};
            for (char c : s) count[c - 'a']++;
            for (int c = 0; c < 26; c++) {
                if (count[c] >= 2) return true;
            }
            return false;
        }

        vector<int> diff;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != goal[i]) diff.push_back(i);
        }

        if (diff.size() != 2) return false;
        int i = diff[0], j = diff[1];
        return s[i] == goal[j] && s[j] == goal[i];
    }
};
