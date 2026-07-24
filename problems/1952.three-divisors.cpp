// @leetcode id=1952 questionId=2083 slug=three-divisors lang=cpp site=leetcode.com title="Three Divisors"
class Solution {
public:
    bool isThree(int n) {
        int count = 0;
        for (int d = 1; d <= n; d++) {
            if (n % d == 0) count++;
        }
        return count == 3;
    }
};
