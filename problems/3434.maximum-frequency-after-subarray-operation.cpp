// @leetcode id=3434 questionId=3751 slug=maximum-frequency-after-subarray-operation lang=cpp site=leetcode.com title="Maximum Frequency After Subarray Operation"
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int totalK = 0;
        for (int x : nums) if (x == k) totalK++;

        int best = totalK;
        for (int v = 1; v <= 50; v++) {
            if (v == k) continue;
            int cur = 0, maxSub = INT_MIN;
            for (int t = 0; t < n; t++) {
                int b = (nums[t] == v ? 1 : 0) - (nums[t] == k ? 1 : 0);
                cur = max(b, cur + b);
                maxSub = max(maxSub, cur);
            }
            best = max(best, totalK + maxSub);
        }
        return best;
    }
};
