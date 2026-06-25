// @leetcode id=3931 questionId=4305 slug=check-adjacent-digit-differences lang=cpp site=leetcode.com title="Check Adjacent Digit Differences"
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (int i = 0; i + 1 < (int)s.size(); i++) {
            if (abs(s[i] - s[i+1]) > 2) return false;
        }
        return true;
    }
};
