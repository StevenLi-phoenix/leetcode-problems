// @leetcode id=2270 questionId=2358 slug=number-of-ways-to-split-array lang=cpp site=leetcode.com title="Number of Ways to Split Array"
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0;
        for (int num : nums) {
            total += num;
        }
        
        long long leftSum = 0;
        int count = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            long long rightSum = total - leftSum;
            
            if (leftSum >= rightSum) {
                count++;
            }
        }
        
        return count;
    }
};
