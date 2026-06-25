// @leetcode id=2507 questionId=2595 slug=smallest-value-after-replacing-with-sum-of-prime-factors lang=cpp site=leetcode.com title="Smallest Value After Replacing With Sum of Prime Factors"
class Solution {
public:
    int smallestValue(int n) {
        auto sumPrimeFactors = [](int x) {
            int s = 0;
            for (int p = 2; (long long)p * p <= x; p++) {
                while (x % p == 0) {
                    s += p;
                    x /= p;
                }
            }
            if (x > 1) s += x;
            return s;
        };
        
        while (true) {
            int next = sumPrimeFactors(n);
            if (next == n) return n;
            n = next;
        }
    }
};
