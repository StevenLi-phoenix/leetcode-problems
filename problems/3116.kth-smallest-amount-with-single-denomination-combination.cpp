// @leetcode id=3116 questionId=3375 slug=kth-smallest-amount-with-single-denomination-combination lang=cpp site=leetcode.com title="Kth Smallest Amount With Single Denomination Combination"
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long hi = (long long)*max_element(coins.begin(), coins.end()) * k;

        auto countLE = [&](long long time) -> long long {
            long long total = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                bool overflow = false;
                int bits = __builtin_popcount(mask);
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        long long g = gcd(l, (long long)coins[i]);
                        long long next = l / g * coins[i];
                        if (next > time) { overflow = true; break; }
                        l = next;
                    }
                }
                if (overflow) continue;
                long long cnt = time / l;
                total += (bits % 2 == 1) ? cnt : -cnt;
            }
            return total;
        };

        long long lo = 1;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
