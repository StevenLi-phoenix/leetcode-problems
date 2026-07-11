// @leetcode id=1095 questionId=1185 slug=find-in-mountain-array lang=cpp site=leetcode.com title="Find in Mountain Array"
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Find the peak via binary search on the slope.
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) lo = mid + 1;
            else hi = mid;
        }
        int peak = lo;

        // Search ascending half.
        lo = 0; hi = peak;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mountainArr.get(mid) < target) lo = mid + 1;
            else hi = mid;
        }
        if (mountainArr.get(lo) == target) return lo;

        // Search descending half.
        lo = peak; hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mountainArr.get(mid) > target) lo = mid + 1;
            else hi = mid;
        }
        if (mountainArr.get(lo) == target) return lo;

        return -1;
    }
};
