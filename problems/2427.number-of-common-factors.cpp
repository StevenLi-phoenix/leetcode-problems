// @leetcode id=2427 questionId=2507 slug=number-of-common-factors lang=cpp site=leetcode.com title="Number of Common Factors"
class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 0;
        for (int x = 1; x <= min(a, b); x++) {
            if (a % x == 0 && b % x == 0) count++;
        }
        return count;
    }
};
