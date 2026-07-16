// @leetcode id=2116 questionId=2221 slug=check-if-a-parentheses-string-can-be-valid lang=cpp site=leetcode.com title="Check if a Parentheses String Can Be Valid"
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;

        int balance = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || locked[i] == '0') balance++;
            else balance--;
            if (balance < 0) return false;
        }

        balance = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || locked[i] == '0') balance++;
            else balance--;
            if (balance < 0) return false;
        }
        return true;
    }
};
