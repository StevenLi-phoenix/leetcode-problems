// @leetcode id=1824 questionId=1952 slug=minimum-sideway-jumps lang=cpp site=leetcode.com title="Minimum Sideway Jumps"
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int dp[3] = {1, 0, 1};
        int n = obstacles.size() - 1;
        for (int i = 1; i <= n; ++i) {
            int obs = obstacles[i];
            for (int lane = 0; lane < 3; ++lane) {
                if (obs == lane + 1) dp[lane] = INT_MAX / 2;
            }
            int best = min({dp[0], dp[1], dp[2]});
            for (int lane = 0; lane < 3; ++lane) {
                if (obs != lane + 1) dp[lane] = min(dp[lane], best + 1);
            }
        }
        return min({dp[0], dp[1], dp[2]});
    }
};
