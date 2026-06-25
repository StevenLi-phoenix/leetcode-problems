// @leetcode id=1827 questionId=1938 slug=minimum-operations-to-make-the-array-increasing lang=cpp site=leetcode.com title="Minimum Operations to Make the Array Increasing"
class Solution {
public:
    int minOperations(vector<int>& nums) {
        long long operations = 0;
        long long prev = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= prev) {
                long long needed = prev + 1 - nums[i];
                operations += needed;
                prev = prev + 1;
            } else {
                prev = nums[i];
            }
        }

        return (int)operations;
    }
};
