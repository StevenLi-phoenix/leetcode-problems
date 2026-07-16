// @leetcode id=991 questionId=1033 slug=broken-calculator lang=cpp site=leetcode.com title="Broken Calculator"
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        long long start = startValue, t = target;
        int ops = 0;
        while (t > start) {
            if (t % 2 == 0) {
                t /= 2;
            } else {
                t += 1;
            }
            ops++;
        }
        return ops + (int)(start - t);
    }
};
