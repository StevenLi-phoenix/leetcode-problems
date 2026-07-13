// @leetcode id=3891 questionId=4149 slug=minimum-increase-to-maximize-special-indices lang=cpp site=leetcode.com title="Minimum Increase to Maximize Special Indices"
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        // A special index needs nums[i] > both neighbors, so two chosen
        // special indices can never be adjacent (they'd need to beat each
        // other). This becomes: pick a max-size independent set of
        // candidate indices on a path, breaking ties by minimum total cost,
        // where cost(i) = the single bump needed so nums[i] exceeds both
        // (untouched) neighbors at once.
        int n = nums.size();
        auto costAt = [&](int i) -> long long {
            long long need = max(nums[i - 1], nums[i + 1]) + 1LL;
            return max(0LL, need - nums[i]);
        };

        // f[i] = {maxCount, minCostForThatCount} using indices 0..i
        vector<pair<long long, long long>> f(n);
        f[0] = {0, 0};
        for (int i = 1; i < n; i++) {
            pair<long long, long long> notSelect = f[i - 1];
            pair<long long, long long> best = notSelect;
            if (i >= 1 && i <= n - 2) {
                pair<long long, long long> prev = (i - 2 >= 0) ? f[i - 2] : make_pair(0LL, 0LL);
                pair<long long, long long> select = {prev.first + 1, prev.second + costAt(i)};
                if (select.first > best.first ||
                    (select.first == best.first && select.second < best.second)) {
                    best = select;
                }
            }
            f[i] = best;
        }
        return f[n - 1].second;
    }
};
