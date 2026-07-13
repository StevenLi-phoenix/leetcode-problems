// @leetcode id=3556 questionId=3815 slug=sum-of-largest-prime-substrings lang=cpp site=leetcode.com title="Sum of Largest Prime Substrings"
class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        auto isPrime = [](long long x) {
            if (x < 2) return false;
            for (long long d = 2; d * d <= x; d++)
                if (x % d == 0) return false;
            return true;
        };

        set<long long> primes;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long long val = stoll(s.substr(i, j - i + 1));
                if (isPrime(val)) primes.insert(val);
            }
        }

        long long sum = 0;
        int count = 0;
        for (auto it = primes.rbegin(); it != primes.rend() && count < 3; ++it, ++count)
            sum += *it;
        return sum;
    }
};
