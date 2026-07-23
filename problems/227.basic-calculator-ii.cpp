// @leetcode id=227 questionId=227 slug=basic-calculator-ii lang=cpp site=leetcode.com title="Basic Calculator II"
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long num = 0;
        char op = '+';
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == n - 1) {
                if (op == '+') {
                    st.push((int)num);
                } else if (op == '-') {
                    st.push(-(int)num);
                } else if (op == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * (int)num);
                } else if (op == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / (int)num);
                }
                op = c;
                num = 0;
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};
