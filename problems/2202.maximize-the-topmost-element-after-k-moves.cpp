// @leetcode id=2202 questionId=1346 slug=maximize-the-topmost-element-after-k-moves lang=cpp site=leetcode.com title="Maximize the Topmost Element After K Moves"
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return nums[0];

        int result = -1;
        if (k < n) result = nums[k];

        int maxSoFar = INT_MIN;
        int limit = min(k, n);
        for (int cnt = 1; cnt <= limit; cnt++) {
            maxSoFar = max(maxSoFar, nums[cnt - 1]);
            int remaining = k - cnt - 1;
            if (remaining >= 0 && (remaining % 2 == 0 || cnt >= 2)) {
                result = max(result, maxSoFar);
            }
        }
        return result;
    }
};
