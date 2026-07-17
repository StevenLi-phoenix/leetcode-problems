// @leetcode id=1494 questionId=1587 slug=parallel-courses-ii lang=cpp site=leetcode.com title="Parallel Courses II"
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prereq(n, 0);
        for (auto& r : relations) {
            int a = r[0] - 1, b = r[1] - 1;
            prereq[b] |= (1 << a);
        }

        int full = 1 << n;
        vector<int> dp(full, INT_MAX);
        dp[0] = 0;

        for (int mask = 0; mask < full; mask++) {
            if (dp[mask] == INT_MAX) continue;

            int available = 0;
            for (int c = 0; c < n; c++) {
                if (!(mask & (1 << c)) && (prereq[c] & mask) == prereq[c]) {
                    available |= (1 << c);
                }
            }
            if (available == 0) continue;

            // enumerate subsets of available with popcount <= k
            for (int sub = available; sub > 0; sub = (sub - 1) & available) {
                if (__builtin_popcount(sub) <= k) {
                    int newMask = mask | sub;
                    if (dp[newMask] > dp[mask] + 1) {
                        dp[newMask] = dp[mask] + 1;
                    }
                }
            }
        }

        return dp[full - 1];
    }
};
