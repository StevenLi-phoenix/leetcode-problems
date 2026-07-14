// @leetcode id=1015 questionId=1064 slug=smallest-integer-divisible-by-k lang=cpp site=leetcode.com title="Smallest Integer Divisible by K"
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int rem = 1 % k;
        for (int len = 1; ; len++) {
            if (rem == 0) return len;
            rem = (rem * 10 + 1) % k;
        }
    }
};
