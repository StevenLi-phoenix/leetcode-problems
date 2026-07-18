// @leetcode id=1872 questionId=2002 slug=stone-game-viii lang=cpp site=leetcode.com title="Stone Game VIII"
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stones[i];

        long long dp = prefix[n];
        for (int i = n - 1; i >= 2; i--) {
            dp = max(dp, prefix[i] - dp);
        }

        return (int)dp;
    }
};
