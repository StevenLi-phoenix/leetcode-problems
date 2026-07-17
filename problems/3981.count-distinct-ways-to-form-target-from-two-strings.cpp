// @leetcode id=3981 questionId=4082 slug=count-distinct-ways-to-form-target-from-two-strings lang=cpp site=leetcode.com title="Count Distinct Ways to Form Target from Two Strings"
class Solution {
public:
    int interleaveCharacters(string word1, string word2, string target) {
        const long long MOD = 1000000007;
        int n1 = word1.size(), n2 = word2.size(), m = target.size();

        vector<vector<long long>> dp(n1 + 1, vector<long long>(n2 + 1, 0));
        dp[0][0] = 1;

        for (char tc : target) {
            // prefix sums along i for each j
            vector<vector<long long>> prefI(n1 + 1, vector<long long>(n2 + 1, 0));
            for (int j = 0; j <= n2; j++) {
                long long run = 0;
                for (int i = 0; i <= n1; i++) {
                    run = (run + dp[i][j]) % MOD;
                    prefI[i][j] = run;
                }
            }
            // prefix sums along j for each i
            vector<vector<long long>> prefJ(n1 + 1, vector<long long>(n2 + 1, 0));
            for (int i = 0; i <= n1; i++) {
                long long run = 0;
                for (int j = 0; j <= n2; j++) {
                    run = (run + dp[i][j]) % MOD;
                    prefJ[i][j] = run;
                }
            }

            vector<vector<long long>> newDp(n1 + 1, vector<long long>(n2 + 1, 0));

            for (int p1 = 0; p1 < n1; p1++) {
                if (word1[p1] != tc) continue;
                for (int j = 0; j <= n2; j++) {
                    newDp[p1 + 1][j] = (newDp[p1 + 1][j] + prefI[p1][j]) % MOD;
                }
            }

            for (int p2 = 0; p2 < n2; p2++) {
                if (word2[p2] != tc) continue;
                for (int i = 0; i <= n1; i++) {
                    newDp[i][p2 + 1] = (newDp[i][p2 + 1] + prefJ[i][p2]) % MOD;
                }
            }

            dp = newDp;
        }

        long long answer = 0;
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                answer = (answer + dp[i][j]) % MOD;
            }
        }

        return (int)answer;
    }
};
