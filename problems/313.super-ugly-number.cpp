// @leetcode id=313 questionId=313 slug=super-ugly-number lang=cpp site=leetcode.com title="Super Ugly Number"
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<long long> ugly(n);
        ugly[0] = 1;
        vector<int> ptr(k, 0);

        for (int i = 1; i < n; i++) {
            long long next = LLONG_MAX;
            for (int j = 0; j < k; j++) {
                next = min(next, ugly[ptr[j]] * primes[j]);
            }
            ugly[i] = next;
            for (int j = 0; j < k; j++) {
                if (ugly[ptr[j]] * primes[j] == next) ptr[j]++;
            }
        }

        return (int)ugly[n - 1];
    }
};
