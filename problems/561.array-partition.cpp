// @leetcode id=561 questionId=561 slug=array-partition lang=cpp site=leetcode.com title="Array Partition"
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i += 2) sum += nums[i];
        return sum;
    }
};
