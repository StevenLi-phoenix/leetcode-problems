// @leetcode id=3995 questionId=4088 slug=minimum-cost-to-convert-string-iii lang=cpp site=leetcode.com title="Minimum Cost to Convert String III"
class Solution {
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n = source.size();
        int m = rules.size();

        vector<int> starCount(m);
        for (int i = 0; i < m; i++) {
            starCount[i] = count(rules[i][0].begin(), rules[i][0].end(), '*');
        }

        const long long INF = LLONG_MAX / 2;
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            if (dp[i - 1] < INF && source[i - 1] == target[i - 1]) {
                dp[i] = min(dp[i], dp[i - 1]);
            }

            for (int r = 0; r < m; r++) {
                const string& pattern = rules[r][0];
                const string& replacement = rules[r][1];
                int L = pattern.size();
                if (L > i) continue;
                int start = i - L;
                if (dp[start] >= INF) continue;

                bool ok = true;
                for (int k = 0; k < L && ok; k++) {
                    char pc = pattern[k];
                    if (pc != '*' && pc != source[start + k]) ok = false;
                    if (replacement[k] != target[start + k]) ok = false;
                }
                if (ok) {
                    dp[i] = min(dp[i], dp[start] + costs[r] + starCount[r]);
                }
            }
        }

        return dp[n] >= INF ? -1 : (int)dp[n];
    }
};
