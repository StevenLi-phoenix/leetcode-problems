// @leetcode id=956 questionId=993 slug=tallest-billboard lang=cpp site=leetcode.com title="Tallest Billboard"
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        // dp[diff] = max value of the smaller side, for a given |sideA - sideB| = diff
        unordered_map<int,int> dp;
        dp[0] = 0;

        for (int r : rods) {
            unordered_map<int,int> newDp = dp;
            for (auto& [diff, small] : dp) {
                // Option 1: add r to the taller side.
                int d1 = diff + r;
                if (!newDp.count(d1) || newDp[d1] < small) newDp[d1] = small;

                // Option 2: add r to the shorter side.
                int d2 = abs(diff - r);
                int shorterSide = min(diff + small, small + r);
                if (!newDp.count(d2) || newDp[d2] < shorterSide) newDp[d2] = shorterSide;
            }
            dp = newDp;
        }

        return dp.count(0) ? dp[0] : 0;
    }
};
