// @leetcode id=2938 questionId=3195 slug=separate-black-and-white-balls lang=cpp site=leetcode.com title="Separate Black and White Balls"
class Solution {
public:
    long long minimumSteps(string s) {
        long long ones = 0, steps = 0;
        for (char c : s) {
            if (c == '1') ones++;
            else steps += ones;
        }
        return steps;
    }
};
