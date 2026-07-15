// @leetcode id=3979 questionId=4341 slug=maximum-valid-pair-sum lang=cpp site=leetcode.com title="Maximum Valid Pair Sum"
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long best = LLONG_MIN;
        int maxLeft = INT_MIN;
        int leftBound = 0;
        for (int j = k; j < n; j++) {
            maxLeft = max(maxLeft, nums[j - k]);
            best = max(best, (long long)maxLeft + nums[j]);
        }
        return (int)best;
    }
};
