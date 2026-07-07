// @leetcode id=2460 questionId=2551 slug=apply-operations-to-an-array lang=cpp site=leetcode.com title="Apply Operations to an Array"
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int writePos = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) swap(nums[writePos++], nums[i]);
        }
        return nums;
    }
};
