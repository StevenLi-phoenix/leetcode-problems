// @leetcode id=2283 questionId=2377 slug=check-if-number-has-equal-digit-count-and-digit-value lang=cpp site=leetcode.com title="Check if Number Has Equal Digit Count and Digit Value"
class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        int cnt[10] = {};
        for (char c : num) cnt[c - '0']++;
        for (int i = 0; i < n; i++) {
            if (cnt[i] != (num[i] - '0')) return false;
        }
        return true;
    }
};
