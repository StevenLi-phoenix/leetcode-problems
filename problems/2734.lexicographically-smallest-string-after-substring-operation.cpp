// @leetcode id=2734 questionId=2828 slug=lexicographically-smallest-string-after-substring-operation lang=cpp site=leetcode.com title="Lexicographically Smallest String After Substring Operation"
class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == 'a') i++;
        if (i == n) {
            s[n - 1] = 'z';
            return s;
        }
        while (i < n && s[i] != 'a') {
            s[i] = s[i] - 1;
            i++;
        }
        return s;
    }
};
