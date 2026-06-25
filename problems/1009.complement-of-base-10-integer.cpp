// @leetcode id=1009 questionId=1054 slug=complement-of-base-10-integer lang=cpp site=leetcode.com title="Complement of Base 10 Integer"
class Solution {
    public:
    int bitwiseComplement(int n) {
    if (n == 0) return 1;
    int mask = 1;
    while (mask <= n) mask <<= 1;
    return mask - 1 - n;
    }
    };
