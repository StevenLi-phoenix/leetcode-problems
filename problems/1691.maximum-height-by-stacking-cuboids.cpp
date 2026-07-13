// @leetcode id=1691 questionId=1367 slug=maximum-height-by-stacking-cuboids lang=cpp site=leetcode.com title="Maximum Height by Stacking Cuboids "
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // Rotating each cuboid so its own dims are sorted ascending is
        // always optimal (maximizes the base while using the smallest
        // side as height only when forced); after that, cuboid i can sit
        // on cuboid j iff each of i's sorted dims is <= j's, which reduces
        // to a standard LIS-on-3-keys DP once cuboids are sorted.
        for (auto& c : cuboids) sort(c.begin(), c.end());
        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        vector<int> dp(n);
        int best = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; j++) {
                if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] &&
                    cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            best = max(best, dp[i]);
        }
        return best;
    }
};
