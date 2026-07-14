// @leetcode id=3192 questionId=3477 slug=minimum-operations-to-make-binary-array-elements-equal-to-one-ii lang=cpp site=leetcode.com title="Minimum Operations to Make Binary Array Elements Equal to One II"
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flip = 0, ops = 0;
        for (int v : nums) {
            int actual = v ^ flip;
            if (actual == 0) {
                flip ^= 1;
                ops++;
            }
        }
        return ops;
    }
};
