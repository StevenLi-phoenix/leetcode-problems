// @leetcode id=1986 questionId=2114 slug=minimum-number-of-work-sessions-to-finish-the-tasks lang=cpp site=leetcode.com title="Minimum Number of Work Sessions to Finish the Tasks"
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int total = 1 << n;
        // dp[mask] = {min sessions, max remaining time} -- negate remaining for pair comparison
        // dp[mask].first = sessions, dp[mask].second = remaining (we want max, so use -rem for pair sort)
        vector<pair<int,int>> dp(total, {INT_MAX, 0});
        dp[0] = {1, sessionTime};
        
        for (int mask = 1; mask < total; mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) continue;
                int prev = mask ^ (1 << i);
                if (dp[prev].first == INT_MAX) continue;
                
                int sess = dp[prev].first;
                int rem = dp[prev].second;
                
                int newSess, newRem;
                if (tasks[i] <= rem) {
                    newSess = sess;
                    newRem = rem - tasks[i];
                } else {
                    newSess = sess + 1;
                    newRem = sessionTime - tasks[i];
                }
                
                // Better: fewer sessions, or same sessions with more remaining time
                if (dp[mask].first == INT_MAX ||
                    newSess < dp[mask].first ||
                    (newSess == dp[mask].first && newRem > dp[mask].second)) {
                    dp[mask] = {newSess, newRem};
                }
            }
        }
        return dp[total - 1].first;
    }
};
