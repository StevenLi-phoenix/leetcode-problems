// @leetcode id=1047 questionId=1128 slug=remove-all-adjacent-duplicates-in-string lang=cpp site=leetcode.com title="Remove All Adjacent Duplicates In String"
class Solution {
public:
    string removeDuplicates(string s) {
        string stack;
        for (char c : s) {
            if (!stack.empty() && stack.back() == c) stack.pop_back();
            else stack.push_back(c);
        }
        return stack;
    }
};
