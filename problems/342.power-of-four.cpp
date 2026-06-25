// @leetcode id=342 questionId=342 slug=power-of-four lang=cpp site=leetcode.com title="Power of Four"
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        // Must be power of 2: only one bit set
        if ((n & (n - 1)) != 0) return false;
        // Bit must be at even position (0, 2, 4, ...)
        // 0x55555555 = 0101...0101 in binary
        return (n & 0x55555555) != 0;
    }
};
