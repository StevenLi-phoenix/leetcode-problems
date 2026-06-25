// @leetcode id=7 questionId=7 slug=reverse-integer lang=cpp site=leetcode.com title="Reverse Integer"
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            
            // Check for overflow before adding the digit
            // If result > INT_MAX/10, then result*10 will overflow
            // If result == INT_MAX/10 and digit > 7, then result*10+digit will overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            
            // Check for underflow for negative numbers
            // If result < INT_MIN/10, then result*10 will underflow
            // If result == INT_MIN/10 and digit < -8, then result*10+digit will underflow
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) {
                return 0;
            }
            
            result = result * 10 + digit;
        }
        return result;
    }
};
