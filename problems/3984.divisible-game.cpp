// @leetcode id=3984 questionId=4188 slug=divisible-game lang=cpp site=leetcode.com title="Divisible Game"
class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        set<int> uniqueVals(nums.begin(), nums.end());
        set<long long> candidates;
        candidates.insert(2);
        for (int v : uniqueVals) {
            for (int d = 1; (long long)d * d <= v; d++) {
                if (v % d == 0) {
                    if (d > 1) candidates.insert(d);
                    int other = v / d;
                    if (other > 1) candidates.insert(other);
                }
            }
        }

        long long bestDiff = LLONG_MIN;
        long long bestK = -1;
        for (long long k : candidates) {
            long long cur = 0, maxSum = LLONG_MIN;
            for (int x : nums) {
                long long val = (x % k == 0) ? x : -x;
                cur = max(cur + val, val);
                maxSum = max(maxSum, cur);
            }
            if (maxSum > bestDiff) {
                bestDiff = maxSum;
                bestK = k;
            } else if (maxSum == bestDiff && k < bestK) {
                bestK = k;
            }
        }

        long long result = ((bestDiff % MOD) * (bestK % MOD)) % MOD;
        result = ((result % MOD) + MOD) % MOD;
        return (int)result;
    }
};
