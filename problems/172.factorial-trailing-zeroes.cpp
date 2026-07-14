// @leetcode id=172 questionId=172 slug=factorial-trailing-zeroes lang=cpp site=leetcode.com title="Factorial Trailing Zeroes"
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for (long long p = 5; p <= n; p *= 5) {
            count += n / p;
        }
        return count;
    }
};
