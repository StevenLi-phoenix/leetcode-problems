// @leetcode id=201 questionId=201 slug=bitwise-and-of-numbers-range lang=cpp site=leetcode.com title="Bitwise AND of Numbers Range"
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return left << shift;
    }
};
