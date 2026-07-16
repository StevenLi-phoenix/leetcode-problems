// @leetcode id=3918 questionId=4297 slug=sum-of-primes-between-number-and-its-reverse lang=cpp site=leetcode.com title="Sum of Primes Between Number and Its Reverse"
class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int r = 0, x = n;
        while (x > 0) { r = r * 10 + x % 10; x /= 10; }

        int lo = min(n, r), hi = max(n, r);
        auto isPrime = [](int v) {
            if (v < 2) return false;
            for (int i = 2; i * i <= v; i++) {
                if (v % i == 0) return false;
            }
            return true;
        };

        int sum = 0;
        for (int v = lo; v <= hi; v++) {
            if (isPrime(v)) sum += v;
        }
        return sum;
    }
};
