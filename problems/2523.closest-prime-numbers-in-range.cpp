// @leetcode id=2523 questionId=2610 slug=closest-prime-numbers-in-range lang=cpp site=leetcode.com title="Closest Prime Numbers in Range"
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isComposite(right + 1, false);
        for (int i = 2; (long long)i * i <= right; i++) {
            if (!isComposite[i]) {
                for (int j = i * i; j <= right; j += i) isComposite[j] = true;
            }
        }

        vector<int> primes;
        for (int i = max(2, left); i <= right; i++) {
            if (!isComposite[i]) primes.push_back(i);
        }

        vector<int> ans = {-1, -1};
        int bestGap = INT_MAX;
        for (size_t i = 1; i < primes.size(); i++) {
            int gap = primes[i] - primes[i - 1];
            if (gap < bestGap) {
                bestGap = gap;
                ans = {primes[i - 1], primes[i]};
            }
        }
        return ans;
    }
};
