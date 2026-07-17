// @leetcode id=1473 questionId=1583 slug=paint-house-iii lang=cpp site=leetcode.com title="Paint House III"
class Solution {
public:
    vector<vector<vector<int>>> memo;
    vector<int>* housesPtr;
    vector<vector<int>>* costPtr;
    int m_, n_, target_;
    const int INF = INT_MAX / 2;

    int solve(int i, int prevColor, int remaining) {
        if (remaining < 0) return INF;
        if (i == m_) return remaining == 0 ? 0 : INF;

        int& memoVal = memo[i][prevColor][remaining];
        if (memoVal != -1) return memoVal;

        int best = INF;
        vector<int>& houses = *housesPtr;
        vector<vector<int>>& cost = *costPtr;

        if (houses[i] != 0) {
            int color = houses[i];
            int newRemaining = (color == prevColor) ? remaining : remaining - 1;
            best = solve(i + 1, color, newRemaining);
        } else {
            for (int c = 1; c <= n_; c++) {
                int newRemaining = (c == prevColor) ? remaining : remaining - 1;
                int res = solve(i + 1, c, newRemaining);
                if (res != INF) {
                    best = min(best, res + cost[i][c - 1]);
                }
            }
        }

        memoVal = best;
        return best;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        m_ = m; n_ = n; target_ = target;
        housesPtr = &houses; costPtr = &cost;
        memo.assign(m, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));

        int result = solve(0, 0, target);
        return result >= INF ? -1 : result;
    }
};
