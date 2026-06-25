// @leetcode id=2044 questionId=2170 slug=count-number-of-maximum-bitwise-or-subsets lang=cpp site=leetcode.com title="Count Number of Maximum Bitwise-OR Subsets"
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        // Compute max OR
        int maxOr = 0;
        for (int x : nums) maxOr |= x;
        
        // Count subsets with OR == maxOr
        int count = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            int orVal = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) orVal |= nums[i];
            }
            if (orVal == maxOr) count++;
        }
        return count;
    }
};
