// @leetcode id=2740 questionId=2845 slug=find-the-value-of-the-partition lang=cpp site=leetcode.com title="Find the Value of the Partition"
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int best = INT_MAX;
        for (int i = 1; i < (int)nums.size(); ++i) {
            best = min(best, nums[i] - nums[i - 1]);
        }
        return best;
    }
};
