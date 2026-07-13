// @leetcode id=81 questionId=81 slug=search-in-rotated-sorted-array-ii lang=cpp site=leetcode.com title="Search in Rotated Sorted Array II"
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return true;

            if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
                // Can't tell which half is sorted; shrink both ends.
                lo++; hi--;
            } else if (nums[lo] <= nums[mid]) {
                // Left half is sorted.
                if (nums[lo] <= target && target < nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            } else {
                // Right half is sorted.
                if (nums[mid] < target && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return false;
    }
};
