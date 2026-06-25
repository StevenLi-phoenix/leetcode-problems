// @leetcode id=3226 questionId=3508 slug=number-of-bit-changes-to-make-two-integers-equal lang=cpp site=leetcode.com title="Number of Bit Changes to Make Two Integers Equal"
class Solution {
public:
    int minChanges(int n, int k) {
        if ((k | n) != n) {
            return -1;
        }

        int diff = n ^ k;
        int count = 0;
        while (diff > 0) {
            count += diff & 1;
            diff >>= 1;
        }

        return count;
    }
};
