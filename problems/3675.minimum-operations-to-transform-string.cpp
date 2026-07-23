// @leetcode id=3675 questionId=3999 slug=minimum-operations-to-transform-string lang=cpp site=leetcode.com title="Minimum Operations to Transform String"
class Solution {
public:
    int minOperations(string s) {
        int m = 26;
        for (char c : s) {
            if (c != 'a') m = min(m, c - 'a');
        }
        return m == 26 ? 0 : 26 - m;
    }
};
