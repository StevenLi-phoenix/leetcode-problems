// @leetcode id=2439 questionId=2530 slug=minimize-maximum-of-array lang=cpp site=leetcode.com title="Minimize Maximum of Array"
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long prefixSum = 0;
        long long best = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            prefixSum += nums[i];
            long long avg = (prefixSum + i) / (i + 1);
            best = max(best, avg);
        }
        return (int)best;
    }
};
