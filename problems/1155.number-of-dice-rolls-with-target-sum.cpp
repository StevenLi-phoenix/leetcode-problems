// @leetcode id=1155 questionId=1263 slug=number-of-dice-rolls-with-target-sum lang=cpp site=leetcode.com title="Number of Dice Rolls With Target Sum"
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int die = 0; die < n; die++) {
            vector<long long> ndp(target + 1, 0);
            for (int t = 0; t <= target; t++) {
                if (dp[t] == 0) continue;
                for (int face = 1; face <= k && t + face <= target; face++) {
                    ndp[t + face] = (ndp[t + face] + dp[t]) % MOD;
                }
            }
            dp = ndp;
        }
        return (int)dp[target];
    }
};
