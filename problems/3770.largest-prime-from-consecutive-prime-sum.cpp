// @leetcode id=3770 questionId=4085 slug=largest-prime-from-consecutive-prime-sum lang=cpp site=leetcode.com title="Largest Prime from Consecutive Prime Sum"
class Solution {
public:
    int largestPrime(int n) {
        // Sieve of Eratosthenes
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Collect all primes
        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) primes.push_back(i);
        }
        
        // Compute consecutive sums starting from 2
        int ans = 0;
        long long sum = 0;
        for (int p : primes) {
            sum += p;
            if (sum > n) break;
            if (isPrime[sum]) {
                ans = sum;
            }
        }
        
        return ans;
    }
};
