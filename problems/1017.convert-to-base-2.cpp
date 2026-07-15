// @leetcode id=1017 questionId=1070 slug=convert-to-base-2 lang=cpp site=leetcode.com title="Convert to Base -2"
class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string result;
        long long num = n;
        while (num != 0) {
            int rem = (int)(num % 2);
            if (rem < 0) rem += 2;
            result += ('0' + rem);
            num = (num - rem) / -2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
