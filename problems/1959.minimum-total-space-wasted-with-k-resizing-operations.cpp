// @leetcode id=1959 questionId=2081 slug=minimum-total-space-wasted-with-k-resizing-operations lang=cpp site=leetcode.com title="Minimum Total Space Wasted With K Resizing Operations"
class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        // dp[i][j] = min wasted space for first i elements using at most j resizes
        // We have k+1 segments (initial + k resizes)
        const int INF = 1e9;
        // dp[j][i] = min wasted space for first i elements with j segments used
        vector<vector<int>> dp(k + 2, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        
        // Precompute: cost[l][r] = wasted space for segment [l, r-1]
        // = (r-l) * max(nums[l..r-1]) - sum(nums[l..r-1])
        
        for (int seg = 1; seg <= k + 1; seg++) {
            for (int i = 0; i < n; i++) {
                if (dp[seg-1][i] == INF) continue;
                int mx = 0, sum = 0;
                for (int j = i; j < n; j++) {
                    mx = max(mx, nums[j]);
                    sum += nums[j];
                    int waste = mx * (j - i + 1) - sum;
                    if (dp[seg-1][i] + waste < dp[seg][j+1]) {
                        dp[seg][j+1] = dp[seg-1][i] + waste;
                    }
                }
            }
        }
        
        int ans = INF;
        for (int seg = 1; seg <= k + 1; seg++) {
            ans = min(ans, dp[seg][n]);
        }
        return ans;
    }
};
