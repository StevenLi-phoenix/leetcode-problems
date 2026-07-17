// @leetcode id=3139 questionId=3402 slug=minimum-cost-to-equalize-array lang=cpp site=leetcode.com title="Minimum Cost to Equalize Array"
class Solution {
public:
    static const long long MOD = 1000000007;

    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int n = nums.size();
        if (n == 1) return 0;

        long long S = 0;
        long long minVal = nums[0], maxVal = nums[0];
        for (int v : nums) {
            S += v;
            minVal = min(minVal, (long long)v);
            maxVal = max(maxVal, (long long)v);
        }

        long long costPerPair = min((long long)cost2, 2LL * cost1);

        auto computeCost = [&](long long target) -> long long {
            long long total = (long long)n * target - S;
            long long mx = target - minVal;
            long long rest = total - mx;
            if (mx > rest) {
                return (mx - rest) * cost1 + rest * costPerPair;
            } else {
                long long pairs = total / 2;
                long long remainder = total % 2;
                return pairs * costPerPair + remainder * cost1;
            }
        };

        vector<long long> candidates;
        for (long long d = 0; d <= 5; d++) candidates.push_back(maxVal + d);
        if (n > 2) {
            long long numerX = S - 2 * minVal;
            long long denom = n - 2;
            long long approx = numerX >= 0 ? numerX / denom : -((-numerX + denom - 1) / denom);
            for (long long d = -5; d <= 5; d++) candidates.push_back(approx + d);
        }

        long long best = LLONG_MAX;
        for (long long t : candidates) {
            if (t < maxVal) continue;
            best = min(best, computeCost(t));
        }

        return (int)(best % MOD);
    }
};
