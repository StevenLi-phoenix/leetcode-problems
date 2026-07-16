// @leetcode id=3107 questionId=3387 slug=minimum-operations-to-make-median-of-array-equal-to-k lang=cpp site=leetcode.com title="Minimum Operations to Make Median of Array Equal to K"
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = n / 2;

        long long ops = 0;
        for (int i = 0; i < n; i++) {
            if (i < m && nums[i] > k) {
                ops += nums[i] - k;
            } else if (i > m && nums[i] < k) {
                ops += k - nums[i];
            } else if (i == m) {
                ops += llabs((long long)nums[i] - k);
            }
        }
        return ops;
    }
};
