// @leetcode id=2294 questionId=2387 slug=partition-array-such-that-maximum-difference-is-k lang=cpp site=leetcode.com title="Partition Array Such That Maximum Difference Is K"
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int groupStart = nums[0];
        for (int x : nums) {
            if (x - groupStart > k) {
                count++;
                groupStart = x;
            }
        }
        return count;
    }
};
