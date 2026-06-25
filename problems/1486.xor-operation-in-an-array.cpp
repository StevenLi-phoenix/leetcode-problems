// @leetcode id=1486 questionId=1610 slug=xor-operation-in-an-array lang=cpp site=leetcode.com title="XOR Operation in an Array"
class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result ^= start + 2 * i;
        }
        return result;
    }
};
