// @leetcode id=3824 questionId=4176 slug=minimum-k-to-reduce-array-within-limit lang=cpp site=leetcode.com title="Minimum K to Reduce Array Within Limit"
class Solution {
public:
    int minimumK(vector<int>& nums) {
        auto cost = [&](long long k) {
            long long total = 0;
            for (int v : nums) total += (v + k - 1) / k;
            return total;
        };

        long long hi = 1;
        while (cost(hi) > hi * hi) hi *= 2;

        long long lo = 1;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (cost(mid) <= mid * mid) hi = mid;
            else lo = mid + 1;
        }
        return (int)lo;
    }
};
