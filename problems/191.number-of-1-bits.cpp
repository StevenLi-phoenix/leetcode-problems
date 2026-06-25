// @leetcode id=191 questionId=191 slug=number-of-1-bits lang=cpp site=leetcode.com title="Number of 1 Bits"
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            n &= n - 1;
            count++;
        }
        return count;
    }
};
