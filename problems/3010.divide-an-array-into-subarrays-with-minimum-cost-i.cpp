// @leetcode id=3010 questionId=3263 slug=divide-an-array-into-subarrays-with-minimum-cost-i lang=cpp site=leetcode.com title="Divide an Array Into Subarrays With Minimum Cost I"
class Solution {
    public:
    int minimumCost(vector<int>& nums) {
    int n = nums.size();
    vector<int> rest(nums.begin()+1, nums.end());
    sort(rest.begin(), rest.end());
    return nums[0] + rest[0] + rest[1];
    }
    };
