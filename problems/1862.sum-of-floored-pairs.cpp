// @leetcode id=1862 questionId=1326 slug=sum-of-floored-pairs lang=cpp site=leetcode.com title="Sum of Floored Pairs"
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<long long> cnt(maxVal + 1, 0);
        for (int v : nums) ++cnt[v];

        vector<long long> prefix(maxVal + 1, 0);
        for (int v = 1; v <= maxVal; ++v) prefix[v] = prefix[v - 1] + cnt[v];

        long long total = 0;
        for (int v = 1; v <= maxVal; ++v) {
            if (cnt[v] == 0) continue;

            long long sumForV = 0;
            for (int k = 1, lo = v; lo <= maxVal; ++k, lo += v) {
                int hi = min((long long)lo + v - 1, (long long)maxVal);
                sumForV += (long long)k * (prefix[hi] - prefix[lo - 1]);
            }

            total = (total + cnt[v] * (sumForV % MOD)) % MOD;
        }
        return (int)total;
    }
};
