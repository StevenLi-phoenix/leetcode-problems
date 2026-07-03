// @leetcode id=3340 questionId=3636 slug=check-balanced-string lang=cpp site=leetcode.com title="Check Balanced String"
class Solution {
public:
    bool isBalanced(string num) {
        int evenSum = 0, oddSum = 0;
        for (int i = 0; i < (int)num.size(); ++i) {
            int d = num[i] - '0';
            if (i % 2 == 0) evenSum += d;
            else oddSum += d;
        }
        return evenSum == oddSum;
    }
};
