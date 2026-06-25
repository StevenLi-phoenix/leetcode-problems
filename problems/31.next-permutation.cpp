// @leetcode id=31 questionId=31 slug=next-permutation lang=cpp site=leetcode.com title="Next Permutation"
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the rightmost position i where nums[i] < nums[i+1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // Step 2: If such position exists, find the rightmost j > i where nums[i] < nums[j]
        if (i >= 0) {
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: Swap nums[i] and nums[j]
            swap(nums[i], nums[j]);
        }
        
        // Step 4: Reverse the suffix starting at nums[i+1]
        reverse(nums.begin() + i + 1, nums.end());
    }
};
