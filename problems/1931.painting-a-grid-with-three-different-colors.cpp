// @leetcode id=1931 questionId=2061 slug=painting-a-grid-with-three-different-colors lang=cpp site=leetcode.com title="Painting a Grid With Three Different Colors"
class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1e9 + 7;

        // Generate all valid column colorings (m cells, 3 colors, adjacent differ).
        vector<vector<int>> states;
        vector<int> cur(m);
        function<void(int)> gen = [&](int i) {
            if (i == m) {
                states.push_back(cur);
                return;
            }
            for (int c = 0; c < 3; ++c) {
                if (i > 0 && cur[i - 1] == c) continue;
                cur[i] = c;
                gen(i + 1);
            }
        };
        gen(0);

        int S = states.size();
        vector<vector<int>> compatible(S);
        for (int i = 0; i < S; ++i) {
            for (int j = 0; j < S; ++j) {
                bool ok = true;
                for (int r = 0; r < m; ++r) {
                    if (states[i][r] == states[j][r]) { ok = false; break; }
                }
                if (ok) compatible[i].push_back(j);
            }
        }

        vector<long long> dp(S, 1);
        for (int col = 1; col < n; ++col) {
            vector<long long> next(S, 0);
            for (int i = 0; i < S; ++i) {
                if (dp[i] == 0) continue;
                for (int j : compatible[i]) {
                    next[j] = (next[j] + dp[i]) % MOD;
                }
            }
            dp = next;
        }

        long long total = 0;
        for (long long v : dp) total = (total + v) % MOD;
        return (int)total;
    }
};
