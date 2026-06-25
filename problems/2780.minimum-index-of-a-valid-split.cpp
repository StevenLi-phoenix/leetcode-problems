// @leetcode id=2780 questionId=2888 slug=minimum-index-of-a-valid-split lang=cpp site=leetcode.com title="Minimum Index of a Valid Split"
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Find dominant element using Boyer-Moore majority vote
        int dominant = nums[0], count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == dominant) count++;
            else if (--count == 0) { dominant = nums[i]; count = 1; }
        }
        
        // Count total occurrences of dominant
        int total = 0;
        for (int x : nums) if (x == dominant) total++;
        
        // Find minimum valid split index
        int leftCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) leftCount++;
            int leftSize = i + 1;
            int rightCount = total - leftCount;
            int rightSize = n - leftSize;
            // Check if dominant is majority in both parts
            if (leftCount * 2 > leftSize && rightCount * 2 > rightSize) {
                return i;
            }
        }
        return -1;
    }
};
