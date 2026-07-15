// @leetcode id=402 questionId=402 slug=remove-k-digits lang=cpp site=leetcode.com title="Remove K Digits"
class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;
        for (char c : num) {
            while (!stack.empty() && k > 0 && stack.back() > c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }

        size_t start = 0;
        while (start < stack.size() && stack[start] == '0') start++;
        stack = stack.substr(start);

        return stack.empty() ? "0" : stack;
    }
};
