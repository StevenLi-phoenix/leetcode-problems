// @leetcode id=282 questionId=282 slug=expression-add-operators lang=cpp site=leetcode.com title="Expression Add Operators"
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        int n = num.size();
        string expr;

        function<void(int, long long, long long)> dfs = [&](int pos, long long curValue, long long lastOperand) {
            if (pos == n) {
                if (curValue == target) result.push_back(expr);
                return;
            }

            for (int len = 1; pos + len <= n; ++len) {
                if (len > 1 && num[pos] == '0') break; // no leading zeros
                string part = num.substr(pos, len);
                long long value = stoll(part);

                int exprLenBefore = expr.size();

                if (pos == 0) {
                    expr += part;
                    dfs(pos + len, value, value);
                    expr.resize(exprLenBefore);
                } else {
                    // '+'
                    expr += "+" + part;
                    dfs(pos + len, curValue + value, value);
                    expr.resize(exprLenBefore);

                    // '-'
                    expr += "-" + part;
                    dfs(pos + len, curValue - value, -value);
                    expr.resize(exprLenBefore);

                    // '*'
                    expr += "*" + part;
                    dfs(pos + len, curValue - lastOperand + lastOperand * value, lastOperand * value);
                    expr.resize(exprLenBefore);
                }
            }
        };

        dfs(0, 0, 0);
        return result;
    }
};
