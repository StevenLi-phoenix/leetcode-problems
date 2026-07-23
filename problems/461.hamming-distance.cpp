// @leetcode id=461 questionId=461 slug=hamming-distance lang=cpp site=leetcode.com title="Hamming Distance"
class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};
