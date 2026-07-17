// @leetcode id=1163 questionId=1133 slug=last-substring-in-lexicographical-order lang=cpp site=leetcode.com title="Last Substring in Lexicographical Order"
class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        int i = 0, j = 1, k = 0;

        while (j + k < n) {
            if (s[i + k] == s[j + k]) {
                k++;
            } else if (s[i + k] < s[j + k]) {
                i = max(i + k + 1, j);
                j = i + 1;
                k = 0;
            } else {
                j = j + k + 1;
                k = 0;
            }
        }

        return s.substr(i);
    }
};
