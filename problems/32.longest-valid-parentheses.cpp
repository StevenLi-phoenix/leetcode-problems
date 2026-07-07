// @leetcode id=32 questionId=32 slug=longest-valid-parentheses lang=cpp site=leetcode.com title="Longest Valid Parentheses"
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stk;
        stk.push_back(-1);
        int best = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') {
                stk.push_back(i);
            } else {
                stk.pop_back();
                if (stk.empty()) {
                    stk.push_back(i);
                } else {
                    best = max(best, i - stk.back());
                }
            }
        }
        return best;
    }
};
