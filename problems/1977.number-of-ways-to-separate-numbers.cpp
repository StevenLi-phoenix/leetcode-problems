// @leetcode id=1977 questionId=2091 slug=number-of-ways-to-separate-numbers lang=cpp site=leetcode.com title="Number of Ways to Separate Numbers"
class Solution {
public:
    int numberOfCombinations(string num) {
        int n = num.size();
        if (num[0] == '0') return 0;

        const int MOD = 1e9 + 7;

        vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (num[i] == num[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
                else lcp[i][j] = 0;
            }
        }

        auto lessEq = [&](int i, int j, int len) -> bool {
            int l = lcp[i][j];
            if (l >= len) return true;
            return num[i + l] < num[j + l];
        };

        // dp[i][len] = ways where first number starting at i has length len (1..n-i)
        vector<vector<int>> dp(n + 1);
        vector<vector<int>> S(n + 1); // suffix sums: S[i][len] = sum_{L>=len} dp[i][L]

        for (int i = 0; i <= n; i++) {
            dp[i].assign(n - i + 2, 0);
            S[i].assign(n - i + 2, 0);
        }

        for (int i = n - 1; i >= 0; i--) {
            if (num[i] == '0') continue; // dp[i][*] stays 0, invalid start

            int maxLen = n - i;
            for (int len = 1; len <= maxLen; len++) {
                int j = i + len;
                long long ways = 0;
                if (j == n) {
                    ways = 1;
                } else {
                    // longer next number (length > len)
                    if (len + 1 <= n - j) ways += S[j][len + 1];
                    else ways += 0;
                    // same-length next number
                    if (len <= n - j && lessEq(i, j, len)) {
                        ways += dp[j][len];
                    }
                }
                dp[i][len] = (int)(ways % MOD);
            }

            for (int len = maxLen; len >= 1; len--) {
                S[i][len] = (int)(((long long)S[i][len + 1] + dp[i][len]) % MOD);
            }
        }

        long long answer = 0;
        for (int len = 1; len <= n; len++) answer = (answer + dp[0][len]) % MOD;

        return (int)answer;
    }
};
