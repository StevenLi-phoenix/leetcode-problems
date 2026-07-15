// @leetcode id=713 questionId=713 slug=subarray-product-less-than-k lang=cpp site=leetcode.com title="Subarray Product Less Than K"
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        long long product = 1;
        int left = 0, count = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};
