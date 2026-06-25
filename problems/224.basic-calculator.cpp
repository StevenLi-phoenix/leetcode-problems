// @leetcode id=224 questionId=224 slug=basic-calculator lang=cpp site=leetcode.com title="Basic Calculator"
class Solution {
public:
    int calculate(string s) {
        stack<long> stk;
        long result = 0, num = 0, sign = 1;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= stk.top(); stk.pop();
                result += stk.top(); stk.pop();
            }
        }
        result += sign * num;
        return (int)result;
    }
};
