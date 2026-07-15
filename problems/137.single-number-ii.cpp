// @leetcode id=137 questionId=137 slug=single-number-ii lang=cpp site=leetcode.com title="Single Number II"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int n : nums) {
            ones = (ones ^ n) & ~twos;
            twos = (twos ^ n) & ~ones;
        }
        return ones;
    }
};
