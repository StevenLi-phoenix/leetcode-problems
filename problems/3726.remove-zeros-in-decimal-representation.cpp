// @leetcode id=3726 questionId=4051 slug=remove-zeros-in-decimal-representation lang=cpp site=leetcode.com title="Remove Zeros in Decimal Representation"
class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        string result = "";
        for (char c : s) {
            if (c != '0') result += c;
        }
        return stoll(result);
    }
};
