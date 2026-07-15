// @leetcode id=2310 questionId=1334 slug=sum-of-numbers-with-units-digit-k lang=cpp site=leetcode.com title="Sum of Numbers With Units Digit K"
class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        int minVal = (k == 0) ? 10 : k;
        for (int n = 1; (long long)n * minVal <= num; n++) {
            if ((n * k) % 10 == num % 10) return n;
        }
        return -1;
    }
};
