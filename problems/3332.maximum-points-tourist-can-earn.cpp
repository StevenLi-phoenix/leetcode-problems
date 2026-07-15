// @leetcode id=3332 questionId=3587 slug=maximum-points-tourist-can-earn lang=cpp site=leetcode.com title="Maximum Points Tourist Can Earn"
class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<int> dp(n, 0);
        for (int day = 0; day < k; day++) {
            vector<int> next(n, INT_MIN);
            for (int c = 0; c < n; c++) {
                next[c] = max(next[c], dp[c] + stayScore[day][c]);
                for (int prev = 0; prev < n; prev++) {
                    if (prev == c) continue;
                    next[c] = max(next[c], dp[prev] + travelScore[prev][c]);
                }
            }
            dp = next;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
