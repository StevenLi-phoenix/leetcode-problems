// @leetcode id=400 questionId=400 slug=nth-digit lang=cpp site=leetcode.com title="Nth Digit"
class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 1;
        long long count = 9;
        long long start = 1;
        long long rem = n;

        while (rem > digits * count) {
            rem -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }

        long long num = start + (rem - 1) / digits;
        int digitIndex = (rem - 1) % digits;
        string s = to_string(num);
        return s[digitIndex] - '0';
    }
};
