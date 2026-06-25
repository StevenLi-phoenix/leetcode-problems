// @leetcode id=405 questionId=405 slug=convert-a-number-to-hexadecimal lang=cpp site=leetcode.com title="Convert a Number to Hexadecimal"
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string hex = "0123456789abcdef";
        string result = "";

        unsigned int n = num;

        while (n > 0) {
            result = hex[n % 16] + result;
            n /= 16;
        }

        return result;
    }
};
