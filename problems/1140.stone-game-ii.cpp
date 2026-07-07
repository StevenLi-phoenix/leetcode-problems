// @leetcode id=1140 questionId=1240 slug=stone-game-ii lang=cpp site=leetcode.com title="Stone Game II"
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) suffixSum[i] = suffixSum[i + 1] + piles[i];

        vector<vector<int>> memo(n, vector<int>(n + 1, -1));

        function<int(int, int)> dp = [&](int i, int m) -> int {
            if (i >= n) return 0;
            if (i + 2 * m >= n) return suffixSum[i];
            if (memo[i][m] != -1) return memo[i][m];

            int best = 0;
            for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
                int take = suffixSum[i] - dp(i + x, max(m, x));
                best = max(best, take);
            }
            memo[i][m] = best;
            return best;
        };

        return dp(0, 1);
    }
};
