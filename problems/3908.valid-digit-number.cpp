// @leetcode id=3908 questionId=4286 slug=valid-digit-number lang=cpp site=leetcode.com title="Valid Digit Number"
class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        char digit = '0' + x;

        bool contains = s.find(digit) != string::npos;
        bool startsWithX = (s[0] == digit);

        return contains && !startsWithX;
    }
};
