// @leetcode id=2864 questionId=3055 slug=maximum-odd-binary-number lang=cpp site=leetcode.com title="Maximum Odd Binary Number"
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int n = s.size();
        string result(n, '0');
        for (int i = 0; i < ones - 1; i++) result[i] = '1';
        result[n - 1] = '1';
        return result;
    }
};
