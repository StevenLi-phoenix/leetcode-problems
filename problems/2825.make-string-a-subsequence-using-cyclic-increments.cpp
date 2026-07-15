// @leetcode id=2825 questionId=3018 slug=make-string-a-subsequence-using-cyclic-increments lang=cpp site=leetcode.com title="Make String a Subsequence Using Cyclic Increments"
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;
        int n2 = str2.size();
        for (int i = 0; i < (int)str1.size() && j < n2; i++) {
            char c = str1[i];
            char cNext = (c == 'z') ? 'a' : c + 1;
            if (c == str2[j] || cNext == str2[j]) j++;
        }
        return j == n2;
    }
};
