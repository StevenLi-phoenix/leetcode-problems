// @leetcode id=1340 questionId=1466 slug=jump-game-v lang=cpp site=leetcode.com title="Jump Game V"
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 0);
        
        // Use memoization with recursion
        function<int(int)> dfs = [&](int i) -> int {
            if (dp[i] != 0) return dp[i];
            dp[i] = 1;
            // Jump right
            for (int x = 1; x <= d && i + x < n; x++) {
                if (arr[i + x] >= arr[i]) break;
                dp[i] = max(dp[i], 1 + dfs(i + x));
            }
            // Jump left
            for (int x = 1; x <= d && i - x >= 0; x++) {
                if (arr[i - x] >= arr[i]) break;
                dp[i] = max(dp[i], 1 + dfs(i - x));
            }
            return dp[i];
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
