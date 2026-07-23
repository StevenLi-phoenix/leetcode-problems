// @leetcode id=3827 questionId=4194 slug=count-monobit-integers lang=cpp site=leetcode.com title="Count Monobit Integers"
class Solution {
public:
    bool isMonobit(int x) {
        if (x == 0) return true;
        int firstBit = x & 1;
        while (x > 0) {
            if ((x & 1) != firstBit) return false;
            x >>= 1;
        }
        return true;
    }

    int countMonobit(int n) {
        int count = 0;
        for (int x = 0; x <= n; x++) {
            if (isMonobit(x)) count++;
        }
        return count;
    }
};
