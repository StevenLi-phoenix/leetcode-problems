// @leetcode id=476 questionId=476 slug=number-complement lang=cpp site=leetcode.com title="Number Complement"
class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (mask & num) mask <<= 1;
        return ~mask & ~num;
    }
};
