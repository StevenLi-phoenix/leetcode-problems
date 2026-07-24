// @leetcode id=2859 questionId=3093 slug=sum-of-values-at-indices-with-k-set-bits lang=cpp site=leetcode.com title="Sum of Values at Indices With K Set Bits"
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (__builtin_popcount(i) == k) sum += nums[i];
        }
        return sum;
    }
};
