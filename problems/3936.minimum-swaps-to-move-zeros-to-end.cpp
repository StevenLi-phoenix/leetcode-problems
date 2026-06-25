// @leetcode id=3936 questionId=4316 slug=minimum-swaps-to-move-zeros-to-end lang=cpp site=leetcode.com title="Minimum Swaps to Move Zeros to End"
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;

        for (int num : nums) {
            if (num == 0) zeroCount++;
        }

        int zerosInPrefix = 0;
        for (int i = 0; i < n - zeroCount; i++) {
            if (nums[i] == 0) zerosInPrefix++;
        }

        return zerosInPrefix;
    }
};
