// @leetcode id=2169 questionId=2288 slug=count-operations-to-obtain-zero lang=cpp site=leetcode.com title="Count Operations to Obtain Zero"
class Solution {
    public:
    int countOperations(int num1, int num2) {
    int ops = 0;
    while (num1 && num2) {
    if (num1 >= num2) num1 -= num2;
    else num2 -= num1;
    ops++;
    }
    return ops;
    }
    };
