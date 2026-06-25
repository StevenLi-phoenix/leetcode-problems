// @leetcode id=1752 questionId=1878 slug=check-if-array-is-sorted-and-rotated lang=cpp site=leetcode.com title="Check if Array Is Sorted and Rotated"
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                drops++;
            }
        }
        return drops <= 1;
    }
};
