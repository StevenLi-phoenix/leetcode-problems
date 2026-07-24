// @leetcode id=1903 questionId=2032 slug=largest-odd-number-in-string lang=cpp site=leetcode.com title="Largest Odd Number in String"
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = (int)num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) return num.substr(0, i + 1);
        }
        return "";
    }
};
