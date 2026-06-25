// @leetcode id=1997 questionId=2124 slug=first-day-where-you-have-been-in-all-the-rooms lang=cpp site=leetcode.com title="First Day Where You Have Been in All the Rooms"
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        const int MOD = 1e9 + 7;
        int n = nextVisit.size();
        vector<long long> dp(n, 0);
        // dp[i] = first day we visit room i for the first time
        // dp[0] = 0
        for (int i = 0; i < n - 1; i++) {
            // From room i, we visit it once (odd), go to nextVisit[i]
            // We need to get back from nextVisit[i] to i (which takes dp[i] - dp[nextVisit[i]] more days)
            // Then we visit room i again (even), go to i+1
            // Total: dp[i+1] = dp[i] + (dp[i] - dp[nextVisit[i]]) + 1 + 1
            //                = 2*dp[i] - dp[nextVisit[i]] + 2
            dp[i + 1] = (2 * dp[i] - dp[nextVisit[i]] + 2 + MOD) % MOD;
        }
        return (int)dp[n - 1];
    }
};
