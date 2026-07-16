// @leetcode id=2779 questionId=2891 slug=maximum-beauty-of-an-array-after-applying-operation lang=cpp site=leetcode.com title="Maximum Beauty of an Array After Applying Operation"
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int best = 0;
        for (int right = 0; right < n; right++) {
            while (nums[right] - nums[left] > 2 * k) left++;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
