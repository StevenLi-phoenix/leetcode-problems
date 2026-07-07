// @leetcode id=446 questionId=446 slug=arithmetic-slices-ii-subsequence lang=cpp site=leetcode.com title="Arithmetic Slices II - Subsequence"
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        // dp[i][d]: count of weak arithmetic subsequences (length >= 2)
        // ending at i with common difference d
        vector<unordered_map<long long, int>> dp(n);
        long long ans = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long d = (long long)nums[i] - nums[j];
                int fromJ = 0;
                auto it = dp[j].find(d);
                if (it != dp[j].end()) fromJ = it->second;

                dp[i][d] += fromJ + 1;
                ans += fromJ; // extending any length>=2 sequence makes length>=3
            }
        }
        return (int)ans;
    }
};
