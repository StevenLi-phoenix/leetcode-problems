// @leetcode id=34 questionId=34 slug=find-first-and-last-position-of-element-in-sorted-array lang=cpp site=leetcode.com title="Find First and Last Position of Element in Sorted Array"
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        
        // Find first position
        int lo = 0, hi = n - 1, first = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                first = mid;
                hi = mid - 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        if (first == -1) return {-1, -1};
        
        // Find last position
        lo = 0; hi = n - 1;
        int last = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                last = mid;
                lo = mid + 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return {first, last};
    }
};
