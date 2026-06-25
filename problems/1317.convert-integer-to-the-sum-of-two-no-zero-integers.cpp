// @leetcode id=1317 questionId=1440 slug=convert-integer-to-the-sum-of-two-no-zero-integers lang=cpp site=leetcode.com title="Convert Integer to the Sum of Two No-Zero Integers"
class Solution {
public:
    bool noZero(int n) {
        while (n > 0) {
            if (n % 10 == 0) return false;
            n /= 10;
        }
        return true;
    }
    
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            if (noZero(a) && noZero(n - a)) {
                return {a, n - a};
            }
        }
        return {};
    }
};
