// @leetcode id=2160 questionId=2264 slug=minimum-sum-of-four-digit-number-after-splitting-digits lang=cpp site=leetcode.com title="Minimum Sum of Four Digit Number After Splitting Digits"
class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());

        int new1 = (s[0] - '0') * 10 + (s[2] - '0');
        int new2 = (s[1] - '0') * 10 + (s[3] - '0');
        return new1 + new2;
    }
};
