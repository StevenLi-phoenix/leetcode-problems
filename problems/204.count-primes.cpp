// @leetcode id=204 questionId=204 slug=count-primes lang=cpp site=leetcode.com title="Count Primes"
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> isComposite(n, false);
        int count = 0;

        for (int i = 2; i < n; ++i) {
            if (!isComposite[i]) {
                ++count;
                for (long long j = (long long)i * i; j < n; j += i) {
                    isComposite[j] = true;
                }
            }
        }
        return count;
    }
};
