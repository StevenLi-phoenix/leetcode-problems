// @leetcode id=3507 questionId=3773 slug=minimum-pair-removal-to-sort-array-i lang=cpp site=leetcode.com title="Minimum Pair Removal to Sort Array I"
class Solution {
public:
    bool isNonDecreasing(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isNonDecreasing(nums)) {
            int minSum = nums[0] + nums[1];
            int idx = 0;

            for (int i = 1; i + 1 < nums.size(); i++) {
                int curSum = nums[i] + nums[i + 1];
                if (curSum < minSum) {
                    minSum = curSum;
                    idx = i;
                }
            }

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            operations++;
        }

        return operations;
    }
};
