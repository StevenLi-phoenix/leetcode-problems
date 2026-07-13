// @leetcode id=2544 questionId=2630 slug=alternating-digit-sum lang=cpp site=leetcode.com title="Alternating Digit Sum"
class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int sum = 0;
        for (size_t i = 0; i < s.size(); i++) {
            int digit = s[i] - '0';
            sum += (i % 2 == 0) ? digit : -digit;
        }
        return sum;
    }
};
