// @leetcode id=238 questionId=238 slug=product-of-array-except-self lang=cpp site=leetcode.com title="Product of Array Except Self"
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // First pass: compute prefix products
        // result[i] = product of nums[0..i-1]
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        
        // Second pass: multiply by suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        
        return result;
    }
};
