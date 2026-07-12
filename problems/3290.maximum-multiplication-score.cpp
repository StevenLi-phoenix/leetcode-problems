// @leetcode id=3290 questionId=3518 slug=maximum-multiplication-score lang=cpp site=leetcode.com title="Maximum Multiplication Score"
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        const long long NEG_INF = LLONG_MIN / 2;
        // dp[k] = best score achievable having matched a[0..k] to some
        // increasing-index prefix of b seen so far.
        vector<long long> dp(4, NEG_INF);
        for (int x : b) {
            for (int k = 3; k >= 0; k--) {
                long long prev = (k == 0) ? 0 : dp[k - 1];
                if (prev == NEG_INF) continue;
                dp[k] = max(dp[k], prev + (long long)a[k] * x);
            }
        }
        return dp[3];
    }
};
