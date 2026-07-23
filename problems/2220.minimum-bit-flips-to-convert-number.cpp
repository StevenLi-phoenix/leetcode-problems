// @leetcode id=2220 questionId=2323 slug=minimum-bit-flips-to-convert-number lang=cpp site=leetcode.com title="Minimum Bit Flips to Convert Number"
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};
