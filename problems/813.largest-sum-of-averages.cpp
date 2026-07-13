// @leetcode id=813 questionId=831 slug=largest-sum-of-averages lang=cpp site=leetcode.com title="Largest Sum of Averages"
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        auto avg = [&](int i, int j) { return (prefix[j] - prefix[i]) / (j - i); };

        // dp[i] = best score using nums[i..n-1] with current partition count
        vector<double> dp(n + 1, 0);
        for (int i = 0; i < n; i++) dp[i] = avg(i, n);

        for (int parts = 2; parts <= k; parts++) {
            vector<double> newDp(n + 1, 0);
            for (int i = 0; i < n; i++) {
                double best = dp[i];
                for (int j = i + 1; j < n; j++) {
                    best = max(best, avg(i, j) + dp[j]);
                }
                newDp[i] = best;
            }
            dp = newDp;
        }
        return dp[0];
    }
};
