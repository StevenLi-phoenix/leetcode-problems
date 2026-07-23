// @leetcode id=3345 questionId=3626 slug=smallest-divisible-digit-product-i lang=cpp site=leetcode.com title="Smallest Divisible Digit Product I"
class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int x = n; ; x++) {
            int product = 1, y = x;
            while (y > 0) {
                product *= y % 10;
                y /= 10;
            }
            if (product % t == 0) return x;
        }
    }
};
