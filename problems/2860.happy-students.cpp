// @leetcode id=2860 questionId=3104 slug=happy-students lang=cpp site=leetcode.com title="Happy Students"
class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for (int k = 0; k <= n; k++) {
            bool leftOk = (k == 0) || (nums[k - 1] < k);
            bool rightOk = (k == n) || (nums[k] > k);
            if (leftOk && rightOk) count++;
        }
        return count;
    }
};
