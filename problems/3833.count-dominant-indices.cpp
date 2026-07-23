// @leetcode id=3833 questionId=4214 slug=count-dominant-indices lang=cpp site=leetcode.com title="Count Dominant Indices"
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        long long suffixSum = 0;
        int count = 0;
        int dominant = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (count > 0 && (long long)nums[i] * count > suffixSum) dominant++;
            suffixSum += nums[i];
            count++;
        }
        return dominant;
    }
};
