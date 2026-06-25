// @leetcode id=1945 questionId=2076 slug=sum-of-digits-of-string-after-convert lang=cpp site=leetcode.com title="Sum of Digits of String After Convert"
class Solution {
public:
    int getLucky(string s, int k) {
        long long num = 0;
        for (char c : s) {
            int val = c - 'a' + 1;
            if (val >= 10) {
                num += val / 10 + val % 10;
            } else {
                num += val;
            }
        }

        for (int i = 1; i < k; i++) {
            long long sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }

        return num;
    }
};
