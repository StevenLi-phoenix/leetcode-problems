// @leetcode id=1671 questionId=1766 slug=minimum-number-of-removals-to-make-mountain-array lang=cpp site=leetcode.com title="Minimum Number of Removals to Make Mountain Array"
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        // left[i] = length of LIS ending at index i (from left)
        vector<int> left(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    left[i] = max(left[i], left[j] + 1);
                }
            }
        }
        
        // right[i] = length of LDS starting at index i (from right)
        vector<int> right(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    right[i] = max(right[i], right[j] + 1);
                }
            }
        }
        
        // Find maximum mountain length
        // Peak must satisfy left[i] > 1 && right[i] > 1 (peak can't be at endpoints)
        int maxMountain = 0;
        for (int i = 1; i < n - 1; i++) {
            if (left[i] > 1 && right[i] > 1) {
                maxMountain = max(maxMountain, left[i] + right[i] - 1);
            }
        }
        
        return n - maxMountain;
    }
};
