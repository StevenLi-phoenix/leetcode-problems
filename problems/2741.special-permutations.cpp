// @leetcode id=2741 questionId=2848 slug=special-permutations lang=cpp site=leetcode.com title="Special Permutations"
class Solution {
public:
    int specialPerm(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<vector<long long>> dp(1 << n, vector<long long>(n, -1));

        function<long long(int, int)> solve = [&](int mask, int last) -> long long {
            if (mask == (1 << n) - 1) return 1;
            if (dp[mask][last] != -1) return dp[mask][last];
            long long total = 0;
            for (int next = 0; next < n; next++) {
                if (mask & (1 << next)) continue;
                if (nums[last] % nums[next] == 0 || nums[next] % nums[last] == 0) {
                    total = (total + solve(mask | (1 << next), next)) % MOD;
                }
            }
            dp[mask][last] = total;
            return total;
        };

        long long result = 0;
        for (int i = 0; i < n; i++) {
            result = (result + solve(1 << i, i)) % MOD;
        }
        return (int)result;
    }
};
