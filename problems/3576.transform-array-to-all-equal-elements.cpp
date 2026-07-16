// @leetcode id=3576 questionId=3876 slug=transform-array-to-all-equal-elements lang=cpp site=leetcode.com title="Transform Array to All Equal Elements"
class Solution {
public:
    bool tryTarget(vector<int>& nums, int k, int target) {
        int n = nums.size();
        vector<int> b(n);
        int sumB = 0;
        for (int i = 0; i < n; i++) {
            b[i] = (nums[i] != target) ? 1 : 0;
            sumB += b[i];
        }
        if (sumB % 2 != 0) return false;

        long long minOps = 0;
        int prefixXor = 0;
        for (int i = 0; i < n - 1; i++) {
            prefixXor ^= b[i];
            minOps += prefixXor;
        }
        return minOps <= k;
    }

    bool canMakeEqual(vector<int>& nums, int k) {
        return tryTarget(nums, k, 1) || tryTarget(nums, k, -1);
    }
};
