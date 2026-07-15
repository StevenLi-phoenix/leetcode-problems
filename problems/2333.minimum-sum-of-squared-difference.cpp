// @leetcode id=2333 questionId=2418 slug=minimum-sum-of-squared-difference lang=cpp site=leetcode.com title="Minimum Sum of Squared Difference"
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> d(n);
        for (int i = 0; i < n; i++) d[i] = llabs(nums1[i] - nums2[i]);
        sort(d.begin(), d.end());

        long long k = (long long)k1 + k2;
        long long totalSum = 0;
        for (long long v : d) totalSum += v;
        if (totalSum <= k) return 0;

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + d[i];

        auto cost = [&](long long X) {
            // count of elements > X, and their sum
            int idx = upper_bound(d.begin(), d.end(), X) - d.begin();
            long long cnt = n - idx;
            long long sum = prefix[n] - prefix[idx];
            return sum - X * cnt;
        };

        long long lo = 0, hi = d[n - 1];
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (cost(mid) <= k) hi = mid;
            else lo = mid + 1;
        }
        long long X = lo;
        long long leftover = k - cost(X);

        int idxAtLeastX = lower_bound(d.begin(), d.end(), X) - d.begin();
        long long countAtLeastX = n - idxAtLeastX;
        long long reduced = min(countAtLeastX, leftover);

        long long result = 0;
        for (int i = 0; i < idxAtLeastX; i++) result += d[i] * d[i];
        result += reduced * (X - 1) * (X - 1);
        result += (countAtLeastX - reduced) * X * X;

        return result;
    }
};
