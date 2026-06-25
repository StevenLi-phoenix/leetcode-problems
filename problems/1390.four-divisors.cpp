// @leetcode id=1390 questionId=1284 slug=four-divisors lang=cpp site=leetcode.com title="Four Divisors"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        const int MAXV = 100000;
        vector<int> spf(MAXV + 1, 0); // smallest prime factor

        // Build SPF sieve
        for (int i = 2; i <= MAXV; i++) {
            if (spf[i] == 0) {
                spf[i] = i;
                if (1LL * i * i <= MAXV) {
                    for (long long j = 1LL * i * i; j <= MAXV; j += i) {
                        if (spf[(int)j] == 0) spf[(int)j] = i;
                    }
                }
            }
        }

        auto sumIfFour = [&](int x) -> long long {
            int orig = x;
            vector<pair<int,int>> fac;

            while (x > 1) {
                int p = spf[x];
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                fac.push_back({p, cnt});
                if ((int)fac.size() > 2) return 0; // more than 2 distinct primes => not 4 divisors
            }

            // Case 1: p^3
            if (fac.size() == 1 && fac[0].second == 3) {
                long long p = fac[0].first;
                long long p2 = p * p;
                long long p3 = p2 * p;
                return 1 + p + p2 + p3;
            }

            // Case 2: p*q with p!=q
            if (fac.size() == 2 && fac[0].second == 1 && fac[1].second == 1) {
                long long p = fac[0].first;
                long long q = fac[1].first;
                return 1 + p + q + orig;
            }

            return 0;
        };

        long long ans = 0;
        for (int x : nums) ans += sumIfFour(x);
        return (int)ans;
    }
};
