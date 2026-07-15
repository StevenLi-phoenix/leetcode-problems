// @leetcode id=2896 questionId=3033 slug=apply-operations-to-make-two-strings-equal lang=cpp site=leetcode.com title="Apply Operations to Make Two Strings Equal"
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> diffs;
        for (size_t i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) diffs.push_back(i);
        }

        int cnt = diffs.size();
        if (cnt % 2 != 0) return -1;
        if (cnt == 0) return 0;

        // dp[i][j]: min cost to resolve diffs[i..j] (inclusive), only valid for even-length ranges.
        vector<vector<long long>> dp(cnt, vector<long long>(cnt, 0));

        auto pairCost = [&](int a, int b) {
            return min((long long)x, (long long)(diffs[b] - diffs[a]));
        };

        for (int len = 2; len <= cnt; len += 2) {
            for (int i = 0; i + len - 1 < cnt; i++) {
                int j = i + len - 1;
                long long best = LLONG_MAX;
                for (int m = i + 1; m <= j; m += 2) {
                    long long left = (i + 1 <= m - 1) ? dp[i + 1][m - 1] : 0;
                    long long right = (m + 1 <= j) ? dp[m + 1][j] : 0;
                    long long candidate = pairCost(i, m) + left + right;
                    best = min(best, candidate);
                }
                dp[i][j] = best;
            }
        }

        return (int)dp[0][cnt - 1];
    }
};
