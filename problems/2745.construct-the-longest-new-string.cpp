// @leetcode id=2745 questionId=2850 slug=construct-the-longest-new-string lang=cpp site=leetcode.com title="Construct the Longest New String"
class Solution {
public:
    int longestString(int x, int y, int z) {
        int base = 4 * min(x, y) + 2 * z;
        if (x != y) base += 2;
        return base;
    }
};
