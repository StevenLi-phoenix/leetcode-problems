// @leetcode id=1626 questionId=1748 slug=best-team-with-no-conflicts lang=cpp site=leetcode.com title="Best Team With No Conflicts"
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (ages[a] != ages[b]) return ages[a] < ages[b];
            return scores[a] < scores[b];
        });

        vector<int> dp(n);
        int best = 0;
        for (int i = 0; i < n; i++) {
            int p = idx[i];
            dp[i] = scores[p];
            for (int j = 0; j < i; j++) {
                int q = idx[j];
                if (scores[q] <= scores[p]) dp[i] = max(dp[i], dp[j] + scores[p]);
            }
            best = max(best, dp[i]);
        }
        return best;
    }
};
