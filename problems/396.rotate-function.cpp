// @leetcode id=396 questionId=396 slug=rotate-function lang=cpp site=leetcode.com title="Rotate Function"
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, f = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += (long long)i * nums[i];
        }
        long long maxF = f;
        for (int k = 1; k < n; k++) {
            f += sum - (long long)n * nums[n - k];
            maxF = max(maxF, f);
        }
        return (int)maxF;
    }
};
