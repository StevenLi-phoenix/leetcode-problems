// @leetcode id=3007 questionId=3240 slug=maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k lang=cpp site=leetcode.com title="Maximum Number That Sum of the Prices Is Less Than or Equal to K"
class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        // Binary search on num
        // For given num, compute accumulated price = sum of prices of 1..num
        // price(n) = count of set bits at positions x, 2x, 3x, ... (1-indexed from LSB)
        
        // Count of set bits at position b (1-indexed) in numbers 1..n:
        // period = 1LL << b, half = 1LL << (b-1)
        // count = (n / period) * half + max(0LL, n % period - half + 1)
        
        auto countSetBitsAtPos = [](long long n, int b) -> long long {
            long long period = 1LL << b;
            long long half = 1LL << (b - 1);
            return (n / period) * half + max(0LL, n % period - half + 1);
        };
        
        auto accumulatedPrice = [&](long long num) -> long long {
            long long total = 0;
            // Check positions x, 2x, 3x, ... up to 50 (log2 of max possible num)
            for (int b = x; b <= 50; b += x) {
                total += countSetBitsAtPos(num, b);
                if (total > 2e15) return (long long)2e15; // prevent overflow
            }
            return total;
        };
        
        long long lo = 1, hi = (long long)2e15, ans = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (accumulatedPrice(mid) <= k) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
