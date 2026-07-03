// @leetcode id=3146 questionId=3412 slug=permutation-difference-between-two-strings lang=cpp site=leetcode.com title="Permutation Difference between Two Strings"
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int posS[26];
        for (int i = 0; i < (int)s.size(); ++i) posS[s[i] - 'a'] = i;

        int diff = 0;
        for (int j = 0; j < (int)t.size(); ++j) {
            diff += abs(posS[t[j] - 'a'] - j);
        }
        return diff;
    }
};
