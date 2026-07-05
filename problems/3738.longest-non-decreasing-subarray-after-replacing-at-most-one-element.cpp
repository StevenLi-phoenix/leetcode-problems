// @leetcode id=3738 questionId=4098 slug=longest-non-decreasing-subarray-after-replacing-at-most-one-element lang=cpp site=leetcode.com title="Longest Non-Decreasing Subarray After Replacing at Most One Element"
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        vector<int> left(n), right(n);
        left[0] = 1;
        for (int i = 1; i < n; ++i) left[i] = (nums[i] >= nums[i - 1]) ? left[i - 1] + 1 : 1;
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) right[i] = (nums[i] <= nums[i + 1]) ? right[i + 1] + 1 : 1;

        int ans = 0;
        for (int i = 0; i < n; ++i) ans = max(ans, left[i]);

        for (int i = 0; i < n; ++i) {
            int cand;
            if (i == 0) cand = right[1] + 1;
            else if (i == n - 1) cand = left[n - 2] + 1;
            else if (nums[i - 1] <= nums[i + 1]) cand = left[i - 1] + right[i + 1] + 1;
            else cand = max(left[i - 1], right[i + 1]) + 1;
            ans = max(ans, min(cand, n));
        }
        return ans;
    }
};
