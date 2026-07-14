// @leetcode id=1887 questionId=2016 slug=reduction-operations-to-make-the-array-elements-equal lang=cpp site=leetcode.com title="Reduction Operations to Make the Array Elements Equal"
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ops = 0;
        int level = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) level++;
            ops += level;
        }
        return (int)ops;
    }
};
