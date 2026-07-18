// @leetcode id=935 questionId=972 slug=knight-dialer lang=cpp site=leetcode.com title="Knight Dialer"
class Solution {
public:
    int knightDialer(int n) {
        const long long MOD = 1000000007;
        vector<vector<int>> moves = {
            {4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9},
            {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}
        };

        vector<long long> dp(10, 1);
        for (int step = 1; step < n; step++) {
            vector<long long> ndp(10, 0);
            for (int d = 0; d < 10; d++) {
                for (int nd : moves[d]) {
                    ndp[nd] = (ndp[nd] + dp[d]) % MOD;
                }
            }
            dp = ndp;
        }

        long long ans = 0;
        for (int d = 0; d < 10; d++) ans = (ans + dp[d]) % MOD;

        return (int)ans;
    }
};
