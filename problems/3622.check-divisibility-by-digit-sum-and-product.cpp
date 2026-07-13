// @leetcode id=3622 questionId=3918 slug=check-divisibility-by-digit-sum-and-product lang=cpp site=leetcode.com title="Check Divisibility by Digit Sum and Product"
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        for (int t = n; t > 0; t /= 10) {
            sum += t % 10;
            product *= t % 10;
        }
        return n % (sum + product) == 0;
    }
};
