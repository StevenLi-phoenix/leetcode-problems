// @leetcode id=738 questionId=738 slug=monotone-increasing-digits lang=cpp site=leetcode.com title="Monotone Increasing Digits"
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int len = s.size();
        int markFrom = len;
        for (int i = len - 1; i > 0; i--) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                markFrom = i;
            }
        }
        for (int i = markFrom; i < len; i++) s[i] = '9';
        return stoi(s);
    }
};
