// @leetcode id=880 questionId=916 slug=decoded-string-at-index lang=cpp site=leetcode.com title="Decoded String at Index"
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;

        for (char c : s) {
            if (isdigit(c)) {
                size *= (c - '0');
            } else {
                size++;
            }
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            k %= size;

            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }

            if (isdigit(s[i])) {
                size /= (s[i] - '0');
            } else {
                size--;
            }
        }

        return "";
    }
};
