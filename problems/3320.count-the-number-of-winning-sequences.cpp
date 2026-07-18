// @leetcode id=3320 questionId=3588 slug=count-the-number-of-winning-sequences lang=cpp site=leetcode.com title="Count The Number of Winning Sequences"
class Solution {
public:
    static const long long MOD = 1000000007;

    // 0=F,1=W,2=E. beats[a][b] = true if a beats b
    bool beatsTable(int a, int b) {
        return (a == 0 && b == 2) || (a == 1 && b == 0) || (a == 2 && b == 1);
    }

    int countWinningSequences(string s) {
        int n = s.size();
        int offset = n;
        int size = 2 * n + 1;

        auto charToIdx = [](char c) {
            if (c == 'F') return 0;
            if (c == 'W') return 1;
            return 2;
        };

        // dp[last][diff]
        vector<vector<long long>> dp(3, vector<long long>(size, 0));
        vector<vector<long long>> ndp(3, vector<long long>(size, 0));

        int aliceMove0 = charToIdx(s[0]);
        for (int bob = 0; bob < 3; bob++) {
            int delta = 0;
            if (beatsTable(bob, aliceMove0)) delta = 1;
            else if (beatsTable(aliceMove0, bob)) delta = -1;
            int idx = offset + delta;
            dp[bob][idx] = (dp[bob][idx] + 1) % MOD;
        }

        for (int i = 1; i < n; i++) {
            for (auto& row : ndp) fill(row.begin(), row.end(), 0);
            int aliceMove = charToIdx(s[i]);

            for (int lastBob = 0; lastBob < 3; lastBob++) {
                for (int d = 0; d < size; d++) {
                    if (dp[lastBob][d] == 0) continue;
                    long long ways = dp[lastBob][d];
                    for (int bob = 0; bob < 3; bob++) {
                        if (bob == lastBob) continue;
                        int delta = 0;
                        if (beatsTable(bob, aliceMove)) delta = 1;
                        else if (beatsTable(aliceMove, bob)) delta = -1;
                        int nd = d + delta;
                        if (nd < 0 || nd >= size) continue;
                        ndp[bob][nd] = (ndp[bob][nd] + ways) % MOD;
                    }
                }
            }

            swap(dp, ndp);
        }

        long long ans = 0;
        for (int bob = 0; bob < 3; bob++) {
            for (int d = offset + 1; d < size; d++) {
                ans = (ans + dp[bob][d]) % MOD;
            }
        }

        return (int)ans;
    }
};
