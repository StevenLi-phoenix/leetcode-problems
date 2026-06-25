// @leetcode id=3487 questionId=3788 slug=maximum-unique-subarray-sum-after-deletion lang=cpp site=leetcode.com title="Maximum Unique Subarray Sum After Deletion"
class Solution {
public:
    int maxSum(vector<int>& nums) {
        // Sum all distinct positive values
        // If no positive values, return the maximum value
        unordered_set<int> seen;
        int result = 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        
        for (int x : nums) {
            if (x > 0 && seen.find(x) == seen.end()) {
                result += x;
                seen.insert(x);
            }
        }
        
        return result > 0 ? result : maxVal;
    }
};
