// @leetcode id=2547 questionId=2633 slug=minimum-cost-to-split-an-array lang=cpp site=leetcode.com title="Minimum Cost to Split an Array"
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            vector<int> freq(n, 0);
            int trimmedLen = 0;
            for (int j = i - 1; j >= 0; j--) {
                int v = nums[j];
                freq[v]++;
                if (freq[v] == 2) trimmedLen += 2;
                else if (freq[v] > 2) trimmedLen++;

                if (dp[j] == INT_MAX) continue;
                int cost = dp[j] + k + trimmedLen;
                if (cost < dp[i]) dp[i] = cost;
            }
        }

        return dp[n];
    }
};
