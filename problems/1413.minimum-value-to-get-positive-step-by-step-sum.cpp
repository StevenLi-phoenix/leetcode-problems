// @leetcode id=1413 questionId=1514 slug=minimum-value-to-get-positive-step-by-step-sum lang=cpp site=leetcode.com title="Minimum Value to Get Positive Step by Step Sum"
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefixSum = 0, minPrefixSum = 0;
        for (int v : nums) {
            prefixSum += v;
            minPrefixSum = min(minPrefixSum, prefixSum);
        }
        return max(1, 1 - minPrefixSum);
    }
};
