// @leetcode id=3011 questionId=3291 slug=find-if-array-can-be-sorted lang=cpp site=leetcode.com title="Find if Array Can Be Sorted"
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int prevMax = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            int bits = __builtin_popcount(nums[i]);
            int curMin = nums[i], curMax = nums[i];
            while (j < n && __builtin_popcount(nums[j]) == bits) {
                curMin = min(curMin, nums[j]);
                curMax = max(curMax, nums[j]);
                j++;
            }
            if (curMin < prevMax) return false;
            prevMax = curMax;
            i = j;
        }
        return true;
    }
};
