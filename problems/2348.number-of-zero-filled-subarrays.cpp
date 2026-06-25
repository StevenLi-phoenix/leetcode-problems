// @leetcode id=2348 questionId=2432 slug=number-of-zero-filled-subarrays lang=cpp site=leetcode.com title="Number of Zero-Filled Subarrays"
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        long long count = 0;
        for (int x : nums) {
            if (x == 0) {
                count++;
                result += count;
            } else {
                count = 0;
            }
        }
        return result;
    }
};
