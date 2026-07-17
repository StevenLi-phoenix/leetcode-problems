// @leetcode id=805 questionId=823 slug=split-array-with-same-average lang=cpp site=leetcode.com title="Split Array With Same Average"
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return false;

        int totalSum = 0;
        for (int x : nums) totalSum += x;

        int maxK = n / 2;
        vector<bitset<300001>> dp(maxK + 1);
        dp[0][0] = 1;

        for (int x : nums) {
            for (int k = maxK; k >= 1; k--) {
                dp[k] |= dp[k - 1] << x;
            }
        }

        for (int k = 1; k <= maxK; k++) {
            if (((long long)k * totalSum) % n == 0) {
                long long target = ((long long)k * totalSum) / n;
                if (target >= 0 && target <= 300000 && dp[k][target]) return true;
            }
        }

        return false;
    }
};
