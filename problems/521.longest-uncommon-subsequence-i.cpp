// @leetcode id=521 questionId=521 slug=longest-uncommon-subsequence-i lang=cpp site=leetcode.com title="Longest Uncommon Subsequence I"
class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) return -1;
        return max(a.size(), b.size());
    }
};
