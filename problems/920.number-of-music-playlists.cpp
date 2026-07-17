// @leetcode id=920 questionId=956 slug=number-of-music-playlists lang=cpp site=leetcode.com title="Number of Music Playlists"
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(goal + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= n; j++) {
                long long newSong = dp[i - 1][j - 1] * (n - j + 1) % MOD;
                long long oldSong = dp[i - 1][j] * max(0, j - k) % MOD;
                dp[i][j] = (newSong + oldSong) % MOD;
            }
        }

        return (int)dp[goal][n];
    }
};
