// @leetcode id=3370 questionId=3676 slug=smallest-number-with-all-set-bits lang=cpp site=leetcode.com title="Smallest Number With All Set Bits"
class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;
        while (x < n) {
            x = x * 2 + 1;
        }
        return x;
    }
};
