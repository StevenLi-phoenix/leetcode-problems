// @leetcode id=1375 questionId=1491 slug=number-of-times-binary-string-is-prefix-aligned lang=cpp site=leetcode.com title="Number of Times Binary String Is Prefix-Aligned"
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int count = 0;
        int maxFlip = 0;
        for (int i = 0; i < (int)flips.size(); i++) {
            maxFlip = max(maxFlip, flips[i]);
            if (maxFlip == i + 1) count++;
        }
        return count;
    }
};
