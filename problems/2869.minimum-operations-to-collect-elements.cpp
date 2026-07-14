// @leetcode id=2869 questionId=3044 slug=minimum-operations-to-collect-elements lang=cpp site=leetcode.com title="Minimum Operations to Collect Elements"
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool> seen(k + 1, false);
        int collected = 0, ops = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ops++;
            if (nums[i] <= k && !seen[nums[i]]) {
                seen[nums[i]] = true;
                collected++;
                if (collected == k) break;
            }
        }
        return ops;
    }
};
