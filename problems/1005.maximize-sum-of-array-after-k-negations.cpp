// @leetcode id=1005 questionId=1047 slug=maximize-sum-of-array-after-k-negations lang=cpp site=leetcode.com title="Maximize Sum Of Array After K Negations"
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n && k > 0 && nums[i] < 0; i++) {
            nums[i] = -nums[i];
            k--;
        }

        int sum = 0;
        int minVal = INT_MAX;
        for (int x : nums) {
            sum += x;
            minVal = min(minVal, x);
        }

        if (k % 2 == 1) sum -= 2 * minVal;
        return sum;
    }
};
