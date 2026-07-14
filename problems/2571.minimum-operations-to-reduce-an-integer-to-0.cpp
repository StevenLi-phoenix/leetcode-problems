// @leetcode id=2571 questionId=2710 slug=minimum-operations-to-reduce-an-integer-to-0 lang=cpp site=leetcode.com title="Minimum Operations to Reduce an Integer to 0"
class Solution {
public:
    int minOperations(int n) {
        int ops = 0;
        while (n > 0) {
            if (n % 2 == 0) {
                n /= 2;
            } else if (n % 4 == 1) {
                n -= 1;
                ops++;
            } else {
                n += 1;
                ops++;
            }
        }
        return ops;
    }
};
