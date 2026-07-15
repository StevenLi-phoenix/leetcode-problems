// @leetcode id=647 questionId=647 slug=palindromic-substrings lang=cpp site=leetcode.com title="Palindromic Substrings"
class Solution {
public:
    int expand(const string& s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int total = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            total += expand(s, i, i);
            total += expand(s, i, i + 1);
        }
        return total;
    }
};
