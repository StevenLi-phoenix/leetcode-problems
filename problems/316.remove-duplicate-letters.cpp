// @leetcode id=316 questionId=316 slug=remove-duplicate-letters lang=cpp site=leetcode.com title="Remove Duplicate Letters"
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, -1);
        for (int i = 0; i < (int)s.size(); i++) lastIndex[s[i] - 'a'] = i;

        vector<bool> onStack(26, false);
        string stack;
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (onStack[c - 'a']) continue;
            while (!stack.empty() && stack.back() > c && lastIndex[stack.back() - 'a'] > i) {
                onStack[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            stack.push_back(c);
            onStack[c - 'a'] = true;
        }
        return stack;
    }
};
