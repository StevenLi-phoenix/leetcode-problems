// @leetcode id=1877 questionId=1988 slug=minimize-maximum-pair-sum-in-array lang=cpp site=leetcode.com title="Minimize Maximum Pair Sum in Array"
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, nums[i] + nums[n - 1 - i]);
        }
        return ans;
    }
};
