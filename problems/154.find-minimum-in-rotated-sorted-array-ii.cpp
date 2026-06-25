// @leetcode id=154 questionId=154 slug=find-minimum-in-rotated-sorted-array-ii lang=cpp site=leetcode.com title="Find Minimum in Rotated Sorted Array II"
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[hi])
                hi = mid;
            else if (nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi--;  // can't decide, shrink safely
        }
        return nums[lo];
    }
};
