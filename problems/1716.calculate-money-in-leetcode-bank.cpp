// @leetcode id=1716 questionId=1817 slug=calculate-money-in-leetcode-bank lang=cpp site=leetcode.com title="Calculate Money in Leetcode Bank"
class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7, rem = n % 7;
        int total = 0;
        for (int w = 0; w < weeks; w++) {
            int monday = 1 + w;
            total += monday * 7 + 21;
        }
        int monday = 1 + weeks;
        for (int i = 0; i < rem; i++) total += monday + i;
        return total;
    }
};
