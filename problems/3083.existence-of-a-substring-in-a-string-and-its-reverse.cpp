// @leetcode id=3083 questionId=3353 slug=existence-of-a-substring-in-a-string-and-its-reverse lang=cpp site=leetcode.com title="Existence of a Substring in a String and Its Reverse"
class Solution {
public:
    bool isSubstringPresent(string s) {
        bool seen[26][26] = {false};
        int n = s.size();
        for (int i = 0; i + 1 < n; i++) {
            seen[s[i] - 'a'][s[i + 1] - 'a'] = true;
        }
        for (int a = 0; a < 26; a++) {
            for (int b = 0; b < 26; b++) {
                if (seen[a][b] && seen[b][a]) return true;
            }
        }
        return false;
    }
};
