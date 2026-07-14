// @leetcode id=326 questionId=326 slug=power-of-three lang=cpp site=leetcode.com title="Power of Three"
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
};
