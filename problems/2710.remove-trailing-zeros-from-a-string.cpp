// @leetcode id=2710 questionId=2819 slug=remove-trailing-zeros-from-a-string lang=cpp site=leetcode.com title="Remove Trailing Zeros From a String"
class Solution {
public:
    string removeTrailingZeros(string num) {
        int i = num.size() - 1;
        while (i >= 0 && num[i] == '0') i--;
        return num.substr(0, i + 1);
    }
};
