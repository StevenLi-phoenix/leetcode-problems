// @leetcode id=2578 questionId=2650 slug=split-with-minimum-sum lang=cpp site=leetcode.com title="Split With Minimum Sum"
class Solution {
public:
    int splitNum(int num) {
        string digits = to_string(num);
        sort(digits.begin(), digits.end());

        string num1, num2;
        for (int i = 0; i < (int)digits.size(); i++) {
            if (i % 2 == 0) num1 += digits[i];
            else num2 += digits[i];
        }

        return stoi(num1) + stoi(num2);
    }
};
