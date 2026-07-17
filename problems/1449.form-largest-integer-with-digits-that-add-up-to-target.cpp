// @leetcode id=1449 questionId=1545 slug=form-largest-integer-with-digits-that-add-up-to-target lang=cpp site=leetcode.com title="Form Largest Integer With Digits That Add up to Target"
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for (int t = 1; t <= target; t++) {
            for (int d = 0; d < 9; d++) {
                int c = cost[d];
                if (t >= c && dp[t - c] != INT_MIN) {
                    dp[t] = max(dp[t], dp[t - c] + 1);
                }
            }
        }

        if (dp[target] <= 0) return "0";

        string result;
        int t = target;
        while (t > 0) {
            for (int d = 8; d >= 0; d--) {
                int c = cost[d];
                if (t >= c && dp[t - c] != INT_MIN && dp[t - c] + 1 == dp[t]) {
                    result += ('1' + d);
                    t -= c;
                    break;
                }
            }
        }
        return result;
    }
};
