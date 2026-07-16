// @leetcode id=1541 questionId=1648 slug=minimum-insertions-to-balance-a-parentheses-string lang=cpp site=leetcode.com title="Minimum Insertions to Balance a Parentheses String"
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                    if (open == 0) res++;
                    else open--;
                } else {
                    res++;
                    if (open > 0) open--;
                    else res++;
                }
            }
        }
        res += open * 2;
        return res;
    }
};
