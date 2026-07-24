// @leetcode id=2481 questionId=2575 slug=minimum-cuts-to-divide-a-circle lang=cpp site=leetcode.com title="Minimum Cuts to Divide a Circle"
class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) return 0;
        return (n % 2 == 0) ? n / 2 : n;
    }
};
