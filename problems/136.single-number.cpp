// @leetcode id=136 questionId=136 slug=single-number lang=cpp site=leetcode.com title="Single Number"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int v : nums) result ^= v;
        return result;
    }
};
