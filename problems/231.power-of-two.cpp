// @leetcode id=231 questionId=231 slug=power-of-two lang=cpp site=leetcode.com title="Power of Two"
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
