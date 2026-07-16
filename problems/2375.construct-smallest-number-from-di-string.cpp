// @leetcode id=2375 questionId=2456 slug=construct-smallest-number-from-di-string lang=cpp site=leetcode.com title="Construct Smallest Number From DI String"
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string result;
        vector<int> stack;
        for (int i = 0; i <= n; i++) {
            stack.push_back(i + 1);
            if (i == n || pattern[i] == 'I') {
                while (!stack.empty()) {
                    result += to_string(stack.back());
                    stack.pop_back();
                }
            }
        }
        return result;
    }
};
