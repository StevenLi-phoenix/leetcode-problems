// @leetcode id=504 questionId=504 slug=base-7 lang=cpp site=leetcode.com title="Base 7"
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool neg = num < 0;
        long long n = abs((long long)num);
        string res;
        while (n > 0) {
            res += char('0' + n % 7);
            n /= 7;
        }
        if (neg) res += '-';
        reverse(res.begin(), res.end());
        return res;
    }
};
