// @leetcode id=905 questionId=941 slug=sort-array-by-parity lang=cpp site=leetcode.com title="Sort Array By Parity"
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            if (nums[left] % 2 == 1) {
                while (right > left && nums[right] % 2 == 1) {
                    right--;
                }
                swap(nums[left], nums[right]);
            }
            left++;
        }

        return nums;
    }
};
