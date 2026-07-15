// @leetcode id=2997 questionId=3249 slug=minimum-number-of-operations-to-make-array-xor-equal-to-k lang=cpp site=leetcode.com title="Minimum Number of Operations to Make Array XOR Equal to K"
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for (int n : nums) x ^= n;
        x ^= k;
        return __builtin_popcount(x);
    }
};
