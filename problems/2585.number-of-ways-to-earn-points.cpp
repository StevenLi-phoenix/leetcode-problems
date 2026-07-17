// @leetcode id=2585 questionId=2648 slug=number-of-ways-to-earn-points lang=cpp site=leetcode.com title="Number of Ways to Earn Points"
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (auto& t : types) {
            int count = t[0], marks = t[1];
            vector<long long> ndp(target + 1, 0);
            for (int s = 0; s <= target; s++) {
                for (int k = 0; k <= count && k * marks <= s; k++) {
                    ndp[s] = (ndp[s] + dp[s - k * marks]) % MOD;
                }
            }
            dp = ndp;
        }

        return (int)dp[target];
    }
};
