// @leetcode id=3505 questionId=3717 slug=minimum-operations-to-make-elements-within-k-subarrays-equal lang=cpp site=leetcode.com title="Minimum Operations to Make Elements Within K Subarrays Equal"
class Solution {
public:
    multiset<long long> lo, hi;
    long long sumLo = 0, sumHi = 0;

    void rebalance() {
        while (lo.size() > hi.size() + 1) {
            auto it = prev(lo.end());
            long long v = *it;
            sumLo -= v;
            lo.erase(it);
            hi.insert(v);
            sumHi += v;
        }
        while (hi.size() > lo.size()) {
            auto it = hi.begin();
            long long v = *it;
            sumHi -= v;
            hi.erase(it);
            lo.insert(v);
            sumLo += v;
        }
    }

    void addNum(long long val) {
        if (lo.empty() || val <= *lo.rbegin()) {
            lo.insert(val);
            sumLo += val;
        } else {
            hi.insert(val);
            sumHi += val;
        }
        rebalance();
    }

    void removeNum(long long val) {
        auto it = lo.find(val);
        if (it != lo.end()) {
            sumLo -= val;
            lo.erase(it);
        } else {
            it = hi.find(val);
            sumHi -= val;
            hi.erase(it);
        }
        rebalance();
    }

    long long getCost() {
        long long median = *lo.rbegin();
        long long costLo = median * (long long)lo.size() - sumLo;
        long long costHi = sumHi - median * (long long)hi.size();
        return costLo + costHi;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int numWindows = n - x + 1;
        vector<long long> cost(numWindows);

        lo.clear(); hi.clear(); sumLo = 0; sumHi = 0;
        for (int i = 0; i < x; i++) addNum(nums[i]);
        cost[0] = getCost();

        for (int i = 1; i < numWindows; i++) {
            removeNum(nums[i - 1]);
            addNum(nums[i + x - 1]);
            cost[i] = getCost();
        }

        const long long INF = LLONG_MAX / 2;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        for (int i = 0; i <= n; i++) dp[0][i] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                if (i >= x) {
                    int windowStart = i - x;
                    if (dp[j - 1][windowStart] < INF) {
                        dp[j][i] = min(dp[j][i], dp[j - 1][windowStart] + cost[windowStart]);
                    }
                }
            }
        }

        return dp[k][n];
    }
};
