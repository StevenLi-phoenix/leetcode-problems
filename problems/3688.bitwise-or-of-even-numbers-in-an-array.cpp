// @leetcode id=3688 questionId=4009 slug=bitwise-or-of-even-numbers-in-an-array lang=cpp site=leetcode.com title="Bitwise OR of Even Numbers in an Array"
class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int result = 0;
        for (int v : nums) if (v % 2 == 0) result |= v;
        return result;
    }
};
