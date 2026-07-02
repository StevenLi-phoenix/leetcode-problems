// @leetcode id=2264 questionId=2346 slug=largest-3-same-digit-number-in-string lang=cpp site=leetcode.com title="Largest 3-Same-Digit Number in String"
class Solution {
public:
    string largestGoodInteger(string num) {
        char best = -1;
        for (int i = 0; i + 2 < (int)num.size(); i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                if (best == -1 || num[i] > best) best = num[i];
            }
        }
        if (best == -1) return "";
        return string(3, best);
    }
};
