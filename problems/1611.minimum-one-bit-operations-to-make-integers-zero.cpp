// @leetcode id=1611 questionId=1732 slug=minimum-one-bit-operations-to-make-integers-zero lang=cpp site=leetcode.com title="Minimum One Bit Operations to Make Integers Zero"
class Solution {
    public:
    int minimumOneBitOperations(int n) {
    int res = 0;
    while (n) {
    res ^= n;
    n >>= 1;
    }
    return res;
    }
    };
