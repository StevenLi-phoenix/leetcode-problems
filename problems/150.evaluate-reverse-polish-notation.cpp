// @leetcode id=150 questionId=150 slug=evaluate-reverse-polish-notation lang=cpp site=leetcode.com title="Evaluate Reverse Polish Notation"
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for (const string& tok : tokens) {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                int b = stack.back(); stack.pop_back();
                int a = stack.back(); stack.pop_back();
                int result = 0;
                if (tok == "+") result = a + b;
                else if (tok == "-") result = a - b;
                else if (tok == "*") result = a * b;
                else result = a / b;
                stack.push_back(result);
            } else {
                stack.push_back(stoi(tok));
            }
        }
        return stack.back();
    }
};
