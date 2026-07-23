// @leetcode id=3512 questionId=3846 slug=minimum-operations-to-make-array-sum-divisible-by-k lang=cpp site=leetcode.com title="Minimum Operations to Make Array Sum Divisible by K"
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) sum += x;
        return sum % k;
    }
};
