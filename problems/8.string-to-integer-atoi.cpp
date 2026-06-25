// @leetcode id=8 questionId=8 slug=string-to-integer-atoi lang=cpp site=leetcode.com title="String to Integer (atoi)"
class Solution {
public:
    int myAtoi(string s) {
        long long result = 0;
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Check if we've reached the end of string
        if (i == n) {
            return 0;
        }
        
        // Step 2: Determine the sign
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        
        // Step 3: Read the digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            result = result * 10 + digit;
            
            // Step 4: Check for overflow
            // If result exceeds INT_MAX range, clamp it
            if (result > INT_MAX) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            i++;
        }
        
        // Apply the sign and return
        return sign * (int)result;
    }
};
