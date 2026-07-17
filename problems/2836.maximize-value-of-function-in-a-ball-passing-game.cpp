// @leetcode id=2836 questionId=3032 slug=maximize-value-of-function-in-a-ball-passing-game lang=cpp site=leetcode.com title="Maximize Value of Function in a Ball Passing Game"
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        int LOG = 1;
        while ((1LL << LOG) <= k) LOG++;
        LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<vector<long long>> sum(LOG, vector<long long>(n));

        for (int i = 0; i < n; i++) {
            up[0][i] = receiver[i];
            sum[0][i] = receiver[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
                sum[j][i] = sum[j - 1][i] + sum[j - 1][up[j - 1][i]];
            }
        }

        long long best = 0;
        for (int i = 0; i < n; i++) {
            long long cur = i;
            int pos = i;
            long long remaining = k;
            for (int j = 0; j < LOG && remaining > 0; j++) {
                if (remaining & (1LL << j)) {
                    cur += sum[j][pos];
                    pos = up[j][pos];
                }
            }
            best = max(best, cur);
        }

        return best;
    }
};
