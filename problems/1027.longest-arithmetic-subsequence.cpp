// @leetcode id=1027 questionId=1087 slug=longest-arithmetic-subsequence lang=cpp site=leetcode.com title="Longest Arithmetic Subsequence"
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int best = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int len = 2;
                auto it = dp[j].find(diff);
                if (it != dp[j].end()) len = it->second + 1;
                dp[i][diff] = max(dp[i][diff], len);
                best = max(best, dp[i][diff]);
            }
        }
        return best;
    }
};
