// @leetcode id=3500 questionId=3765 slug=minimum-cost-to-divide-array-into-subarrays lang=cpp site=leetcode.com title="Minimum Cost to Divide Array Into Subarrays"
class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();
        const long long INF = LLONG_MAX / 2;

        vector<long long> prefixNums(n + 1, 0), prefixCost(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixNums[i + 1] = prefixNums[i] + nums[i];
            prefixCost[i + 1] = prefixCost[i] + cost[i];
        }

        struct Line {
            long long m, b;
            long long eval(long long x) const { return m * x + b; }
        };

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));
        dp[0][0] = 0;

        for (int p = 1; p <= n; ++p) {
            vector<Line> lines;
            size_t ptr = 0;

            auto bad = [](const Line& l1, const Line& l2, const Line& l3) {
                __int128 lhs = (__int128)(l3.b - l1.b) * (l1.m - l2.m);
                __int128 rhs = (__int128)(l2.b - l1.b) * (l1.m - l3.m);
                return lhs <= rhs;
            };

            for (int j = p; j <= n; ++j) {
                int l = j - 1;
                if (dp[l][p - 1] < INF) {
                    Line nl{-prefixCost[l], dp[l][p - 1]};
                    while (lines.size() >= 2 && bad(lines[lines.size() - 2], lines[lines.size() - 1], nl)) {
                        lines.pop_back();
                    }
                    lines.push_back(nl);
                    if (ptr >= lines.size()) ptr = lines.size() - 1;
                }

                if (lines.empty()) continue;

                long long X = prefixNums[j] + (long long)k * p;
                while (ptr + 1 < lines.size() && lines[ptr + 1].eval(X) <= lines[ptr].eval(X)) ++ptr;

                long long minVal = lines[ptr].eval(X);
                dp[j][p] = X * prefixCost[j] + minVal;
            }
        }

        long long ans = INF;
        for (int p = 1; p <= n; ++p) ans = min(ans, dp[n][p]);
        return ans;
    }
};
