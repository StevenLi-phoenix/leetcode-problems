// @leetcode id=3432 questionId=3704 slug=count-partitions-with-even-sum-difference lang=cpp site=leetcode.com title="Count Partitions with Even Sum Difference"
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        for (int v : nums) total += v;
        if (total % 2 != 0) return 0;
        return (int)nums.size() - 1;
    }
};
