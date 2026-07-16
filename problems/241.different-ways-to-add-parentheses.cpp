// @leetcode id=241 questionId=241 slug=different-ways-to-add-parentheses lang=cpp site=leetcode.com title="Different Ways to Add Parentheses"
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> memo;
        return solve(expression, memo);
    }

private:
    vector<int> solve(const string& expr, unordered_map<string, vector<int>>& memo) {
        auto it = memo.find(expr);
        if (it != memo.end()) return it->second;

        vector<int> result;
        bool isNumber = true;
        for (int i = 0; i < (int)expr.size(); i++) {
            char c = expr[i];
            if (c == '+' || c == '-' || c == '*') {
                isNumber = false;
                vector<int> left = solve(expr.substr(0, i), memo);
                vector<int> right = solve(expr.substr(i + 1), memo);
                for (int a : left) {
                    for (int b : right) {
                        if (c == '+') result.push_back(a + b);
                        else if (c == '-') result.push_back(a - b);
                        else result.push_back(a * b);
                    }
                }
            }
        }
        if (isNumber) result.push_back(stoi(expr));

        memo[expr] = result;
        return result;
    }
};
