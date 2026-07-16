// @leetcode id=2708 questionId=2754 slug=maximum-strength-of-a-group lang=cpp site=leetcode.com title="Maximum Strength of a Group"
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        long long best = LLONG_MIN;
        for (int mask = 1; mask < (1 << n); mask++) {
            long long product = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) product *= nums[i];
            }
            best = max(best, product);
        }
        return best;
    }
};
