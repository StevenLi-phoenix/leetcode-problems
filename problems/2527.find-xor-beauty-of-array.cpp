// @leetcode id=2527 questionId=2621 slug=find-xor-beauty-of-array lang=cpp site=leetcode.com title="Find Xor-Beauty of Array"
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int result = 0;
        for (int x : nums) result ^= x;
        return result;
    }
};
