// @leetcode id=2908 questionId=3176 slug=minimum-sum-of-mountain-triplets-i lang=cpp site=leetcode.com title="Minimum Sum of Mountain Triplets I"
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int minSum = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] < nums[j] && nums[k] < nums[j]) {
                        minSum = min(minSum, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};
