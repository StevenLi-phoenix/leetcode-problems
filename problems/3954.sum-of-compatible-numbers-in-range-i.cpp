// @leetcode id=3954 questionId=4319 slug=sum-of-compatible-numbers-in-range-i lang=cpp site=leetcode.com title="Sum of Compatible Numbers in Range I"
class Solution {
public:
    long long sumOfGoodIntegers(int n, int k) {
        long long sum = 0;
        for (int x = max(1, n - k); x <= n + k; x++) {
            if ((n & x) == 0) {
                sum += x;
            }
        }
        return sum;
    }
};
