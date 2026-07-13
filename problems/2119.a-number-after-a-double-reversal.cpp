// @leetcode id=2119 questionId=2238 slug=a-number-after-a-double-reversal lang=cpp site=leetcode.com title="A Number After a Double Reversal"
class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num == 0 || num % 10 != 0;
    }
};
