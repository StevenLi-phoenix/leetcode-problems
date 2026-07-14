// @leetcode id=413 questionId=413 slug=arithmetic-slices lang=cpp site=leetcode.com title="Arithmetic Slices"
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int cur = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                cur++;
                total += cur;
            } else {
                cur = 0;
            }
        }
        return total;
    }
};
