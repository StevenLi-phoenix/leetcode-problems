// @leetcode id=152 questionId=152 slug=maximum-product-subarray lang=cpp site=leetcode.com title="Maximum Product Subarray"
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0], minP = nums[0], best = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            int x = nums[i];
            if (x < 0) swap(maxP, minP);
            maxP = max(x, maxP * x);
            minP = min(x, minP * x);
            best = max(best, maxP);
        }
        return best;
    }
};
