// @leetcode id=371 questionId=371 slug=sum-of-two-integers lang=cpp site=leetcode.com title="Sum of Two Integers"
class Solution {
public:
    int getSum(int a, int b) {
        unsigned int ua = a, ub = b;
        while (ub != 0) {
            unsigned int carry = ua & ub;
            ua = ua ^ ub;
            ub = carry << 1;
        }
        return (int)ua;
    }
};
