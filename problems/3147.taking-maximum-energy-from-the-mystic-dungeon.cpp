// @leetcode id=3147 questionId=3383 slug=taking-maximum-energy-from-the-mystic-dungeon lang=cpp site=leetcode.com title="Taking Maximum Energy From the Mystic Dungeon"
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--)
            dp[i] = energy[i] + (i + k < n ? dp[i + k] : 0);

        int best = INT_MIN;
        for (int v : dp) best = max(best, v);
        return best;
    }
};
