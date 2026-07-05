// @leetcode id=258 questionId=258 slug=add-digits lang=cpp site=leetcode.com title="Add Digits"
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};
