// @leetcode id=233 questionId=233 slug=number-of-digit-one lang=cpp site=leetcode.com title="Number of Digit One"
class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        for (long long place = 1; place <= n; place *= 10) {
            long long higher = n / (place * 10);
            long long current = (n / place) % 10;
            long long lower = n % place;

            if (current == 0) {
                count += higher * place;
            } else if (current == 1) {
                count += higher * place + lower + 1;
            } else {
                count += (higher + 1) * place;
            }
        }
        return (int)count;
    }
};
