// @leetcode id=1879 questionId=1989 slug=minimum-xor-sum-of-two-arrays lang=cpp site=leetcode.com title="Minimum XOR Sum of Two Arrays"
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == INT_MAX) continue;
            int i = __builtin_popcount(mask);
            if (i >= n) continue;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;
                int nmask = mask | (1 << j);
                int cost = dp[mask] + (nums1[i] ^ nums2[j]);
                if (cost < dp[nmask]) dp[nmask] = cost;
            }
        }

        return dp[(1 << n) - 1];
    }
};
