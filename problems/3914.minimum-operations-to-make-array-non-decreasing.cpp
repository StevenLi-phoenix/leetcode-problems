// @leetcode id=3914 questionId=4270 slug=minimum-operations-to-make-array-non-decreasing lang=cpp site=leetcode.com title="Minimum Operations to Make Array Non Decreasing"
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long add = 0, cost = 0;
        long long prevVal = nums[0];
        for (int i = 1; i < n; i++) {
            long long required = prevVal - nums[i];
            long long newAdd = max(add, required);
            cost += max(0LL, newAdd - add);
            add = newAdd;
            prevVal = nums[i] + add;
        }
        return cost;
    }
};
