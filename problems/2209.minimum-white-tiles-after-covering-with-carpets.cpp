// @leetcode id=2209 questionId=2311 slug=minimum-white-tiles-after-covering-with-carpets lang=cpp site=leetcode.com title="Minimum White Tiles After Covering With Carpets"
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> dp(numCarpets + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[0][i + 1] = dp[0][i] + (floor[i] - '0');
        }

        for (int c = 1; c <= numCarpets; c++) {
            for (int i = 0; i < n; i++) {
                int skip = dp[c][i] + (floor[i] - '0');
                int coverStart = max(0, i - carpetLen + 1);
                int cover = dp[c - 1][coverStart];
                dp[c][i + 1] = min(skip, cover);
            }
        }

        return dp[numCarpets][n];
    }
};
