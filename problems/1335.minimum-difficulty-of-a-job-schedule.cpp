// @leetcode id=1335 questionId=1457 slug=minimum-difficulty-of-a-job-schedule lang=cpp site=leetcode.com title="Minimum Difficulty of a Job Schedule"
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        const int INF = INT_MAX / 2;
        vector<int> dp(n + 1, INF), ndp(n + 1, INF);
        dp[0] = 0;

        for (int k = 1; k <= d; k++) {
            fill(ndp.begin(), ndp.end(), INF);
            for (int i = k; i <= n; i++) {
                int maxD = 0;
                for (int j = i; j >= k; j--) {
                    maxD = max(maxD, jobDifficulty[j - 1]);
                    if (dp[j - 1] == INF) continue;
                    ndp[i] = min(ndp[i], dp[j - 1] + maxD);
                }
            }
            dp = ndp;
        }

        return dp[n] >= INF ? -1 : dp[n];
    }
};
