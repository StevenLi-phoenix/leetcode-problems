// @leetcode id=1780 questionId=1889 slug=check-if-number-is-a-sum-of-powers-of-three lang=cpp site=leetcode.com title="Check if Number is a Sum of Powers of Three"
class Solution {
public:
    bool checkPowersOfThree(int n) {
        // Convert n to base 3, check no digit is 2
        // If any digit in base-3 representation is 2, return false
        while (n > 0) {
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};
