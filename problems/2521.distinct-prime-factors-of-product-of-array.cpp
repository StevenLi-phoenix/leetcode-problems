// @leetcode id=2521 questionId=2609 slug=distinct-prime-factors-of-product-of-array lang=cpp site=leetcode.com title="Distinct Prime Factors of Product of Array"
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> primes;
        for (int n : nums) {
            // Find all prime factors of n
            for (int p = 2; p * p <= n; p++) {
                if (n % p == 0) {
                    primes.insert(p);
                    while (n % p == 0) n /= p;
                }
            }
            if (n > 1) primes.insert(n);
        }
        return primes.size();
    }
};
