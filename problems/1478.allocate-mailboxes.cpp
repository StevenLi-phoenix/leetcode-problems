// @leetcode id=1478 questionId=1571 slug=allocate-mailboxes lang=cpp site=leetcode.com title="Allocate Mailboxes"
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());

        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int lo = i, hi = j, sum = 0;
                while (lo < hi) {
                    sum += houses[hi] - houses[lo];
                    lo++;
                    hi--;
                }
                cost[i][j] = sum;
            }
        }

        const int INF = INT_MAX / 2;
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for (int b = 1; b <= k; b++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[b - 1][j] == INF) continue;
                    dp[b][i] = min(dp[b][i], dp[b - 1][j] + cost[j][i - 1]);
                }
            }
        }

        return dp[k][n];
    }
};
