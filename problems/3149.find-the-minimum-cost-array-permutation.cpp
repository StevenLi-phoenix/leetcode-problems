// @leetcode id=3149 questionId=3431 slug=find-the-minimum-cost-array-permutation lang=cpp site=leetcode.com title="Find the Minimum Cost Array Permutation"
class Solution {
public:
    int n;
    vector<int>* numsPtr;
    vector<vector<long long>> memo;
    vector<vector<bool>> computed;

    int cost(int u, int v) {
        return abs(u - (*numsPtr)[v]);
    }

    long long g(int mask, int last) {
        if (mask == (1 << n) - 1) return cost(last, 0);
        if (computed[mask][last]) return memo[mask][last];

        long long best = LLONG_MAX;
        for (int v = 1; v < n; v++) {
            if (mask & (1 << v)) continue;
            best = min(best, (long long)cost(last, v) + g(mask | (1 << v), v));
        }

        computed[mask][last] = true;
        memo[mask][last] = best;
        return best;
    }

    vector<int> findPermutation(vector<int>& nums) {
        n = nums.size();
        numsPtr = &nums;
        memo.assign(1 << n, vector<long long>(n, 0));
        computed.assign(1 << n, vector<bool>(n, false));

        vector<int> result;
        result.push_back(0);
        int mask = 1;
        int last = 0;

        while (mask != (1 << n) - 1) {
            long long target = g(mask, last);
            for (int v = 1; v < n; v++) {
                if (mask & (1 << v)) continue;
                if ((long long)cost(last, v) + g(mask | (1 << v), v) == target) {
                    result.push_back(v);
                    mask |= (1 << v);
                    last = v;
                    break;
                }
            }
        }

        return result;
    }
};
