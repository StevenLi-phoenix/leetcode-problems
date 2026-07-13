// @leetcode id=837 questionId=867 slug=new-21-game lang=cpp site=leetcode.com title="New 21 Game"
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0; // Alice already stops at 0 points, and n >= k = 0.

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double windowSum = 1.0; // sum of dp[i] for i in [max(0,cur-maxPts), cur-1] ∩ [0,k-1]
        double ans = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;
            if (i < k) windowSum += dp[i];
            if (i - maxPts >= 0 && i - maxPts < k) windowSum -= dp[i - maxPts];
            if (i >= k) ans += dp[i];
        }
        return ans;
    }
};
