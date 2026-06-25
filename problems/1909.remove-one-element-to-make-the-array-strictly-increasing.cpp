// @leetcode id=1909 questionId=2020 slug=remove-one-element-to-make-the-array-strictly-increasing lang=cpp site=leetcode.com title="Remove One Element to Make the Array Strictly Increasing"
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        auto isIncreasing = [&](int skip) {
            int prev = INT_MIN;
            for (int i = 0; i < nums.size(); i++) {
                if (i == skip) continue;
                if (nums[i] <= prev) return false;
                prev = nums[i];
            }
            return true;
        };
        
        // Find first violation
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] >= nums[i + 1]) {
                // Try removing i or i+1
                return isIncreasing(i) || isIncreasing(i + 1);
            }
        }
        
        return true; // Already strictly increasing
    }
};
