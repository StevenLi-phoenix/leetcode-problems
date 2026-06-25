// @leetcode id=3658 questionId=3995 slug=gcd-of-odd-and-even-sums lang=cpp site=leetcode.com title="GCD of Odd and Even Sums"
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // sumOdd = n*n, sumEven = n*(n+1)
        // GCD(n*n, n*(n+1)) = n * GCD(n, n+1) = n * 1 = n
        return n;
    }
};
