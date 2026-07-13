// @leetcode id=3796 questionId=3807 slug=find-maximum-value-in-a-constrained-sequence lang=cpp site=leetcode.com title="Find Maximum Value in a Constrained Sequence"
class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        // Propagate an upper bound for a[i] from every constraint (a[0]=0
        // and each restriction) both forward and backward through the
        // allowed-step graph; the tightest bound at each index accounts for
        // every constraint on both sides, and the answer is the largest
        // such bound over all positions.
        vector<long long> ub(n, LLONG_MAX / 2);
        ub[0] = 0;
        for (auto& r : restrictions) ub[r[0]] = min(ub[r[0]], (long long)r[1]);

        for (int i = 1; i < n; i++) ub[i] = min(ub[i], ub[i - 1] + diff[i - 1]);
        for (int i = n - 2; i >= 0; i--) ub[i] = min(ub[i], ub[i + 1] + diff[i]);

        long long best = 0;
        for (long long v : ub) best = max(best, v);
        return (int)best;
    }
};
