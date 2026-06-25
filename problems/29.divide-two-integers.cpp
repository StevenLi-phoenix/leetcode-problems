// @leetcode id=29 questionId=29 slug=divide-two-integers lang=cpp site=leetcode.com title="Divide Two Integers"
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        long long dvd = labs((long long)dividend);
        long long dvs = labs((long long)divisor);
        
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        long long quotient = 0;
        
        while (dvd >= dvs) {
            long long temp = dvs;
            long long count = 1;
            
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }
            
            dvd -= temp;
            quotient += count;
        }
        
        quotient = sign * quotient;
        
        if (quotient > INT_MAX) quotient = INT_MAX;
        if (quotient < INT_MIN) quotient = INT_MIN;
        
        return (int)quotient;
    }
};
