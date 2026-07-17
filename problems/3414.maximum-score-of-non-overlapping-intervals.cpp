// @leetcode id=3414 questionId=3562 slug=maximum-score-of-non-overlapping-intervals lang=cpp site=leetcode.com title="Maximum Score of Non-overlapping Intervals"
class Solution {
public:
    struct State {
        long long score;
        vector<int> indices; // sorted ascending original indices
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score) return a.score > b.score;
        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return intervals[a][1] < intervals[b][1];
        });

        vector<long long> rSorted(n);
        for (int i = 0; i < n; i++) rSorted[i] = intervals[order[i]][1];

        vector<int> prevIdx(n);
        for (int i = 0; i < n; i++) {
            long long l = intervals[order[i]][0];
            int cnt = lower_bound(rSorted.begin(), rSorted.end(), l) - rSorted.begin();
            prevIdx[i] = cnt;
        }

        vector<vector<State>> dp(5, vector<State>(n + 1, {0, {}}));

        for (int i = 1; i <= n; i++) {
            int idx = order[i - 1];
            long long weight = intervals[idx][2];
            int j = prevIdx[i - 1];

            for (int k = 0; k <= 4; k++) {
                State skip = dp[k][i - 1];
                if (k == 0) {
                    dp[k][i] = skip;
                    continue;
                }
                State takeBase = dp[k - 1][j];
                State take;
                take.score = takeBase.score + weight;
                take.indices = takeBase.indices;
                take.indices.push_back(idx);
                sort(take.indices.begin(), take.indices.end());

                dp[k][i] = better(skip, take) ? skip : take;
            }
        }

        return dp[4][n].indices;
    }
};
