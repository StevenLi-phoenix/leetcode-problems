// @leetcode id=2012 questionId=2138 slug=sum-of-beauty-in-the-array lang=cpp site=leetcode.com title="Sum of Beauty in the Array"
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMax(n), suffixMin(n);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) suffixMin[i] = min(suffixMin[i + 1], nums[i]);

        int total = 0;
        for (int i = 1; i < n - 1; i++) {
            if (prefixMax[i - 1] < nums[i] && nums[i] < suffixMin[i + 1]) {
                total += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                total += 1;
            }
        }
        return total;
    }
};
