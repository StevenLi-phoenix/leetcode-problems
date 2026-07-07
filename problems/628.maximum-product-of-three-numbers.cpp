// @leetcode id=628 questionId=628 slug=maximum-product-of-three-numbers lang=cpp site=leetcode.com title="Maximum Product of Three Numbers"
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int top3 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int twoNegOnePos = nums[0] * nums[1] * nums[n - 1];
        return max(top3, twoNegOnePos);
    }
};
