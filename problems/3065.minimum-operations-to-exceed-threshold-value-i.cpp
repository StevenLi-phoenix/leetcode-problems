// @leetcode id=3065 questionId=3331 slug=minimum-operations-to-exceed-threshold-value-i lang=cpp site=leetcode.com title="Minimum Operations to Exceed Threshold Value I"
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        for (int x : nums) {
            if (x < k) count++;
        }
        return count;
    }
};
