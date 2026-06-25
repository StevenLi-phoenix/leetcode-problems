// @leetcode id=3950 questionId=4307 slug=exactly-one-consecutive-set-bits-pair lang=cpp site=leetcode.com title="Exactly One Consecutive Set Bits Pair"
class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count = 0;
        while (n > 0) {
            if ((n & 3) == 3) {
                count++;
            }
            n >>= 1;
        }
        return count == 1;
    }
};
