// @leetcode id=1556 questionId=1660 slug=thousand-separator lang=cpp site=leetcode.com title="Thousand Separator"
class Solution {
public:
    string thousandSeparator(int n) {
        string digits = to_string(n);
        string result;
        int count = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            result += digits[i];
            count++;
            if (count % 3 == 0 && i != 0) result += '.';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
