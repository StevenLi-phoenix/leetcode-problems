// @leetcode id=926 questionId=962 slug=flip-string-to-monotone-increasing lang=cpp site=leetcode.com title="Flip String to Monotone Increasing"
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0;
        int flips = 0;
        for (char c : s) {
            if (c == '1') {
                ones++;
            } else {
                flips = min(flips + 1, ones);
            }
        }
        return flips;
    }
};
