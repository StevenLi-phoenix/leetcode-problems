// @leetcode id=922 questionId=958 slug=sort-array-by-parity-ii lang=cpp site=leetcode.com title="Sort Array By Parity II"
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 1;
        while (even < n && odd < n) {
            if (nums[even] % 2 == 0) {
                even += 2;
            } else if (nums[odd] % 2 == 1) {
                odd += 2;
            } else {
                swap(nums[even], nums[odd]);
            }
        }
        return nums;
    }
};
