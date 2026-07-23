// @leetcode id=1281 questionId=1406 slug=subtract-the-product-and-sum-of-digits-of-an-integer lang=cpp site=leetcode.com title="Subtract the Product and Sum of Digits of an Integer"
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while (n > 0) {
            int digit = n % 10;
            product *= digit;
            sum += digit;
            n /= 10;
        }
        return product - sum;
    }
};
