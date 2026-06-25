// @leetcode id=3618 questionId=3936 slug=split-array-by-prime-indices lang=cpp site=leetcode.com title="Split Array by Prime Indices"
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        // Sieve of Eratosthenes to find primes up to n-1
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        if (n > 1) isPrime[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        long long sumA = 0, sumB = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime[i]) {
                sumA += nums[i];
            } else {
                sumB += nums[i];
            }
        }
        return abs(sumA - sumB);
    }
};
