// @leetcode id=2894 questionId=3172 slug=divisible-and-non-divisible-sums-difference lang=cpp site=leetcode.com title="Divisible and Non-divisible Sums Difference"
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) num2 += i;
            else num1 += i;
        }
        return num1 - num2;
    }
};
