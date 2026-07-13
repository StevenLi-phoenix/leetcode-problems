// @leetcode id=1434 questionId=1531 slug=number-of-ways-to-wear-different-hats-to-each-other lang=cpp site=leetcode.com title="Number of Ways to Wear Different Hats to Each Other"
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        const long long MOD = 1'000'000'007;
        int n = hats.size();
        vector<vector<int>> peopleForHat(41);
        for (int p = 0; p < n; p++)
            for (int h : hats[p]) peopleForHat[h].push_back(p);

        int fullMask = (1 << n) - 1;
        vector<long long> dp(1 << n, 0);
        dp[0] = 1;

        for (int h = 1; h <= 40; h++) {
            vector<long long> ndp = dp; // option: nobody takes hat h
            for (int mask = 0; mask <= fullMask; mask++) {
                if (dp[mask] == 0) continue;
                for (int p : peopleForHat[h]) {
                    if (mask & (1 << p)) continue;
                    int nmask = mask | (1 << p);
                    ndp[nmask] = (ndp[nmask] + dp[mask]) % MOD;
                }
            }
            dp = move(ndp);
        }
        return (int)dp[fullMask];
    }
};
