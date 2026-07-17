// @leetcode id=1639 questionId=1744 slug=number-of-ways-to-form-a-target-string-given-a-dictionary lang=cpp site=leetcode.com title="Number of Ways to Form a Target String Given a Dictionary"
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const long long MOD = 1000000007;
        int L = words[0].size();
        int m = target.size();

        vector<vector<long long>> colCount(L, vector<long long>(26, 0));
        for (auto& w : words) {
            for (int k = 0; k < L; k++) colCount[k][w[k] - 'a']++;
        }

        vector<long long> dp(m + 1, 0);
        dp[0] = 1;

        for (int k = 0; k < L; k++) {
            for (int i = m - 1; i >= 0; i--) {
                long long c = colCount[k][target[i] - 'a'];
                if (c > 0 && dp[i] > 0) {
                    dp[i + 1] = (dp[i + 1] + dp[i] * c) % MOD;
                }
            }
        }

        return (int)dp[m];
    }
};
