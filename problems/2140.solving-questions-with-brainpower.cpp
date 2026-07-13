// @leetcode id=2140 questionId=2262 slug=solving-questions-with-brainpower lang=cpp site=leetcode.com title="Solving Questions With Brainpower"
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int points = questions[i][0], skip = questions[i][1];
            long long solveVal = points + (i + skip + 1 < n ? dp[i + skip + 1] : 0);
            dp[i] = max(dp[i + 1], solveVal);
        }
        return dp[0];
    }
};
