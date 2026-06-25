// @leetcode id=961 questionId=1001 slug=n-repeated-element-in-size-2n-array lang=cpp site=leetcode.com title="N-Repeated Element in Size 2N Array"
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int m = (int)nums.size();
        for (int i = 0; i < m; i++) {
            if (i + 1 < m && nums[i] == nums[i + 1]) return nums[i];
            if (i + 2 < m && nums[i] == nums[i + 2]) return nums[i];
            if (i + 3 < m && nums[i] == nums[i + 3]) return nums[i];
        }
        return -1; // should never happen given constraints
    }
};
