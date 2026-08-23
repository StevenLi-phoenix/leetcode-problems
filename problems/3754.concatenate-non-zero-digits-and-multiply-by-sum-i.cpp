// @leetcode id=3754 questionId=4135 slug=concatenate-non-zero-digits-and-multiply-by-sum-i lang=cpp site=leetcode.com title="Concatenate Non-Zero Digits and Multiply by Sum I"
class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string x;
        long long sum = 0;
        for (char c : s) {
            if (c != '0') {
                x += c;
                sum += (c - '0');
            }
        }
        if (x.empty()) return 0;
        long long xnum = stoll(x);
        return xnum * sum;
    }
};
