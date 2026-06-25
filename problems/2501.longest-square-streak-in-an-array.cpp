// @leetcode id=2501 questionId=2586 slug=longest-square-streak-in-an-array lang=cpp site=leetcode.com title="Longest Square Streak in an Array"
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> st(nums.begin(), nums.end());
        unordered_map<long long, int> dp;
        sort(nums.begin(), nums.end());
        int ans = -1;
        for (int x : nums) {
            long long sq = (long long)x * x;
            if (st.count(sq)) {
                dp[sq] = max(dp[sq], (dp.count(x) ? dp[x] : 1) + 1);
                ans = max(ans, dp[sq]);
            } else {
                if (!dp.count(x)) dp[x] = 1;
            }
        }
        return ans;
    }
};
