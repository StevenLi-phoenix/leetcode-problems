// @leetcode id=829 questionId=856 slug=consecutive-numbers-sum lang=cpp site=leetcode.com title="Consecutive Numbers Sum"
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // n = k*a + k*(k-1)/2 for k consecutive terms starting at a >= 1,
        // so a = (n - k*(k-1)/2) / k must be a positive integer.
        int count = 0;
        for (long long k = 1; k * (k - 1) / 2 < n; k++) {
            long long rem = n - k * (k - 1) / 2;
            if (rem % k == 0) count++;
        }
        return count;
    }
};
