// @leetcode id=946 questionId=983 slug=validate-stack-sequences lang=cpp site=leetcode.com title="Validate Stack Sequences"
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stack;
        int j = 0;
        for (int x : pushed) {
            stack.push_back(x);
            while (!stack.empty() && stack.back() == popped[j]) {
                stack.pop_back();
                j++;
            }
        }
        return stack.empty();
    }
};
