// @leetcode id=2040 questionId=2150 slug=kth-smallest-product-of-two-sorted-arrays lang=cpp site=leetcode.com title="Kth Smallest Product of Two Sorted Arrays"
class Solution {
public:
    long long floorDiv(long long a, long long b) {
        long long q = a / b, r = a % b;
        if (r != 0 && ((r < 0) != (b < 0))) q--;
        return q;
    }

    long long ceilDiv(long long a, long long b) {
        return -floorDiv(-a, b);
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int m = nums2.size();

        auto countLE = [&](long long P) -> long long {
            long long count = 0;
            for (int x : nums1) {
                if (x > 0) {
                    long long threshold = floorDiv(P, x);
                    count += upper_bound(nums2.begin(), nums2.end(), threshold) - nums2.begin();
                } else if (x < 0) {
                    long long posX = -x;
                    long long threshold = ceilDiv(-P, posX);
                    count += nums2.end() - lower_bound(nums2.begin(), nums2.end(), threshold);
                } else {
                    if (0 <= P) count += m;
                }
            }
            return count;
        };

        long long lo = -10000000000LL, hi = 10000000000LL;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};
