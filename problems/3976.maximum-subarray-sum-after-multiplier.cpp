// @leetcode id=3976 questionId=3730 slug=maximum-subarray-sum-after-multiplier lang=cpp site=leetcode.com title="Maximum Subarray Sum After Multiplier"
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long best1 = solve(nums, k, true);
        long long best2 = solve(nums, k, false);
        return max(best1, best2);
    }

private:
    long long solve(vector<int>& nums, int k, bool multiply) {
        const long long NEG_INF = LLONG_MIN / 2;
        long long dp1 = NEG_INF, dp2 = NEG_INF, dp3 = NEG_INF;
        long long best = NEG_INF;

        for (int x : nums) {
            long long modVal;
            if (multiply) {
                modVal = (long long)x * k;
            } else {
                if (x >= 0) modVal = x / k;
                else modVal = -((-(long long)x) / k);
            }

            long long newDp1 = max(dp1 + x, (long long)x);
            long long newDp2 = max(dp1 + modVal, dp2 + modVal);
            newDp2 = max(newDp2, modVal);
            long long newDp3 = max(dp2 + x, dp3 + x);

            dp1 = newDp1;
            dp2 = newDp2;
            dp3 = newDp3;

            best = max({best, dp1, dp2, dp3});
        }
        return best;
    }
};
