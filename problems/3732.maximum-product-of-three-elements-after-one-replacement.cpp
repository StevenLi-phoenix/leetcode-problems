// @leetcode id=3732 questionId=4101 slug=maximum-product-of-three-elements-after-one-replacement lang=cpp site=leetcode.com title="Maximum Product of Three Elements After One Replacement"
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        const long long LIMIT = 100000;

        vector<long long> v(nums.begin(), nums.end());
        sort(v.begin(), v.end());

        long long candidates[3] = {v[0] * v[1], v[n - 1] * v[n - 2], v[0] * v[n - 1]};
        long long bestPairAbs = 0;
        for (long long c : candidates) bestPairAbs = max(bestPairAbs, llabs(c));
        long long bestWithReplacement = bestPairAbs * LIMIT;

        long long best = bestWithReplacement;
        if (n > 3) {
            long long fromTop = v[n - 1] * v[n - 2] * v[n - 3];
            long long fromMix = v[n - 1] * v[0] * v[1];
            best = max(best, max(fromTop, fromMix));
        }
        return best;
    }
};
