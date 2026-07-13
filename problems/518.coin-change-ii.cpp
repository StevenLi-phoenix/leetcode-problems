// @leetcode id=518 questionId=518 slug=coin-change-ii lang=cpp site=leetcode.com title="Coin Change II"
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Intermediate combination counts for sums other than `amount` can
        // blow up combinatorially with many coins, even though the final
        // answer is guaranteed to fit in an int; cap values to avoid
        // overflow since we only need dp[amount] to be exact.
        const long long CAP = 4e18;
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int s = coin; s <= amount; s++) {
                dp[s] = min(dp[s] + dp[s - coin], CAP);
            }
        }
        return (int)dp[amount];
    }
};
