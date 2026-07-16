// @leetcode id=3196 questionId=3464 slug=maximize-total-cost-of-alternating-subarrays lang=cpp site=leetcode.com title="Maximize Total Cost of Alternating Subarrays"
class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = (i % 2 == 0) ? nums[i] : -nums[i];
        }
        vector<long long> prefixB(n + 1, 0);
        for (int i = 0; i < n; i++) prefixB[i + 1] = prefixB[i] + b[i];

        const long long NEG_INF = LLONG_MIN / 2;
        long long runningMaxEven = -prefixB[0];
        long long runningMaxOdd = NEG_INF;

        vector<long long> dp(n);
        for (int i = 0; i < n; i++) {
            long long optEven = prefixB[i + 1] + runningMaxEven;
            long long optOdd = -prefixB[i + 1] + runningMaxOdd;
            dp[i] = max(optEven, optOdd);

            int l = i + 1;
            if (l % 2 == 0) {
                runningMaxEven = max(runningMaxEven, dp[i] - prefixB[l]);
            } else {
                runningMaxOdd = max(runningMaxOdd, dp[i] + prefixB[l]);
            }
        }
        return dp[n - 1];
    }
};
