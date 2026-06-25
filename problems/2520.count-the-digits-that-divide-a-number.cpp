// @leetcode id=2520 questionId=2608 slug=count-the-digits-that-divide-a-number lang=cpp site=leetcode.com title="Count the Digits That Divide a Number"
class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            if (num % digit == 0) count++;
            temp /= 10;
        }
        return count;
    }
};
