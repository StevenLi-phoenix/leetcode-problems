// @leetcode id=3789 questionId=4147 slug=minimum-cost-to-acquire-required-items lang=cpp site=leetcode.com title="Minimum Cost to Acquire Required Items"
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        auto cost = [&](long long x) {
            long long remaining1 = max(0LL, (long long)need1 - x);
            long long remaining2 = max(0LL, (long long)need2 - x);
            return x * costBoth + remaining1 * cost1 + remaining2 * cost2;
        };

        long long best = LLONG_MAX;
        for (long long x : {0LL, (long long)min(need1, need2), (long long)max(need1, need2)}) {
            best = min(best, cost(x));
        }
        return best;
    }
};
