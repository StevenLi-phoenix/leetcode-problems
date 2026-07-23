// @leetcode id=2180 questionId=2298 slug=count-integers-with-even-digit-sum lang=cpp site=leetcode.com title="Count Integers With Even Digit Sum"
class Solution {
public:
    int countEven(int num) {
        int count = 0;
        for (int i = 1; i <= num; i++) {
            int sum = 0, x = i;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            if (sum % 2 == 0) count++;
        }
        return count;
    }
};
