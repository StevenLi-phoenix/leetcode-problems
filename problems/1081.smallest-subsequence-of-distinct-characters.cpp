// @leetcode id=1081 questionId=1159 slug=smallest-subsequence-of-distinct-characters lang=cpp site=leetcode.com title="Smallest Subsequence of Distinct Characters"
class Solution {
public:
    string smallestSubsequence(string s) {
        int lastIdx[26];
        for (int i = 0; i < 26; i++) lastIdx[i] = -1;
        for (int i = 0; i < (int)s.size(); i++) lastIdx[s[i] - 'a'] = i;

        bool inStack[26] = {false};
        string stack;
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (inStack[c - 'a']) continue;
            while (!stack.empty() && stack.back() > c && lastIdx[stack.back() - 'a'] > i) {
                inStack[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            stack.push_back(c);
            inStack[c - 'a'] = true;
        }
        return stack;
    }
};
