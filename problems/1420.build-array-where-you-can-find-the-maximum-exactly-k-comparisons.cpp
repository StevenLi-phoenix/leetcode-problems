// @leetcode id=1420 questionId=1535 slug=build-array-where-you-can-find-the-maximum-exactly-k-comparisons lang=cpp site=leetcode.com title="Build Array Where You Can Find The Maximum Exactly K Comparisons"
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const long long MOD = 1e9 + 7;
        if (k == 0) return 0;
        // dp[v][c] = number of ways to fill prefix with max value v and search_cost c
        vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, 0));
        for (int v = 1; v <= m; v++) dp[v][1] = 1;

        for (int i = 2; i <= n; i++) {
            vector<vector<long long>> ndp(m + 1, vector<long long>(k + 1, 0));
            vector<vector<long long>> prefix(m + 1, vector<long long>(k + 1, 0));
            for (int v = 1; v <= m; v++)
                for (int c = 1; c <= k; c++)
                    prefix[v][c] = (prefix[v - 1][c] + dp[v][c]) % MOD;

            for (int v = 1; v <= m; v++) {
                for (int c = 1; c <= k; c++) {
                    long long same = (v * dp[v][c]) % MOD;
                    long long extend = prefix[v - 1][c - 1];
                    ndp[v][c] = (same + extend) % MOD;
                }
            }
            dp = ndp;
        }

        long long answer = 0;
        for (int v = 1; v <= m; v++) answer = (answer + dp[v][k]) % MOD;
        return (int)answer;
    }
};
