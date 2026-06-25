// @leetcode id=1049 questionId=1130 slug=last-stone-weight-ii lang=cpp site=leetcode.com title="Last Stone Weight II"
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;
        for (int s : stones) total += s;
        int half = total / 2;
        vector<bool> dp(half + 1, false);
        dp[0] = true;
        for (int s : stones) {
            for (int j = half; j >= s; j--) {
                if (dp[j - s]) dp[j] = true;
            }
        }
        for (int j = half; j >= 0; j--) {
            if (dp[j]) return total - 2 * j;
        }
        return total;
    }
};
